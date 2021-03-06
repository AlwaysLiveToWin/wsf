/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <axis2_util.h>
#include <oxs_asym_ctx.h>
#include <oxs_x509_cert.h>
#include <oxs_error.h>

struct oxs_asym_ctx_t
{
    axis2_char_t *algorithm;
    axis2_char_t *st_ref_pattern;
    oxs_asym_ctx_operation_t operation;
    oxs_x509_cert_t *certificate;
    openssl_pkey_t *private_key;
};


/*Public functions*/

AXIS2_EXTERN
oxs_asym_ctx_t *AXIS2_CALL
oxs_asym_ctx_create(const axutil_env_t *env)
{
    oxs_asym_ctx_t *asym_ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    asym_ctx = AXIS2_MALLOC(env->allocator, sizeof(oxs_asym_ctx_t));
    if (!asym_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    asym_ctx->algorithm = NULL;
    asym_ctx->st_ref_pattern = NULL;
    asym_ctx->operation = -1;
    asym_ctx->certificate = NULL;
    asym_ctx->private_key = NULL;

    return asym_ctx;
}


AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_free(oxs_asym_ctx_t *asym_ctx,
                  const axutil_env_t *env)
{

    if (asym_ctx->algorithm)
    {
        AXIS2_FREE(env->allocator, asym_ctx->algorithm);
        asym_ctx->algorithm = NULL;
    }

    if (asym_ctx->st_ref_pattern)
    {
        AXIS2_FREE(env->allocator, asym_ctx->st_ref_pattern);
        asym_ctx->st_ref_pattern = NULL;
    }
    
    /**
     * in current impleemtnation we set the certificate found in the signature processing 
     * to rampart context. Because of that rampart context must free the cert. But have to 
     * fix the free logic when we use certificate directly from file.
     */
    
    /*if (asym_ctx->certificate)
    {
        oxs_x509_cert_free(asym_ctx->certificate, env);
        asym_ctx->certificate = NULL;
    }*/

    if (asym_ctx->private_key)
    {
        openssl_pkey_free(asym_ctx->private_key, env);
        asym_ctx->private_key = NULL;
    }

    AXIS2_FREE(env->allocator,  asym_ctx);
    asym_ctx = NULL;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_char_t *AXIS2_CALL
oxs_asym_ctx_get_algorithm(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->algorithm;
}

AXIS2_EXTERN
axis2_char_t *AXIS2_CALL
oxs_asym_ctx_get_st_ref_pattern(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->st_ref_pattern;
}

AXIS2_EXTERN
oxs_asym_ctx_operation_t AXIS2_CALL
oxs_asym_ctx_get_operation(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->operation;
}

AXIS2_EXTERN
openssl_pkey_t *AXIS2_CALL
oxs_asym_ctx_get_private_key(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{

    return asym_ctx->private_key;
}

AXIS2_EXTERN
oxs_x509_cert_t *AXIS2_CALL
oxs_asym_ctx_get_certificate(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{

    return asym_ctx->certificate;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_algorithm(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    axis2_char_t *algorithm)
{

    if (asym_ctx->algorithm)
    {
        AXIS2_FREE(env->allocator, asym_ctx->algorithm);
        asym_ctx->algorithm = NULL;
    }
    asym_ctx->algorithm = axutil_strdup(env, algorithm);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_st_ref_pattern(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    axis2_char_t *st_ref_pattern)
{
    if (asym_ctx->st_ref_pattern)
    {
        AXIS2_FREE(env->allocator, asym_ctx->st_ref_pattern);
        asym_ctx->st_ref_pattern = NULL;
    }
    asym_ctx->st_ref_pattern = axutil_strdup(env, st_ref_pattern);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_operation(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    oxs_asym_ctx_operation_t operation)
{

    asym_ctx->operation = operation;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_certificate(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    oxs_x509_cert_t *certificate)
{

    if (asym_ctx->certificate)
    {
        oxs_x509_cert_free(asym_ctx->certificate, env);
        asym_ctx->certificate = NULL;
    }
    asym_ctx->certificate = certificate;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_private_key(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    openssl_pkey_t *private_key)
{

    if (asym_ctx->private_key)
    {
        openssl_pkey_free(asym_ctx->private_key, env);
        asym_ctx->private_key = NULL;
    }
    asym_ctx->private_key = private_key;
    return AXIS2_SUCCESS;
}




