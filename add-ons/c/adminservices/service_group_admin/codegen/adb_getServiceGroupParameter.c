/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


        /**
         * adb_getServiceGroupParameter.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_getServiceGroupParameter.h"
        
               /*
                * implmentation of the getServiceGroupParameter|http://org.apache.axis2/xsd element
                */
           


        struct adb_getServiceGroupParameter
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axis2_char_t* property_serviceGroupName;

                
                axis2_bool_t is_valid_serviceGroupName;
            axis2_char_t* property_paramName;

                
                axis2_bool_t is_valid_paramName;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_getServiceGroupParameter_t* AXIS2_CALL
        adb_getServiceGroupParameter_create(
            const axutil_env_t *env)
        {
            adb_getServiceGroupParameter_t *_getServiceGroupParameter = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _getServiceGroupParameter = (adb_getServiceGroupParameter_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_getServiceGroupParameter_t));

            if(NULL == _getServiceGroupParameter)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_getServiceGroupParameter, 0, sizeof(adb_getServiceGroupParameter_t));

            _getServiceGroupParameter->property_Type = axutil_strdup(env, "adb_getServiceGroupParameter");
            _getServiceGroupParameter->property_serviceGroupName  = NULL;
                  _getServiceGroupParameter->is_valid_serviceGroupName  = AXIS2_FALSE;
            _getServiceGroupParameter->property_paramName  = NULL;
                  _getServiceGroupParameter->is_valid_paramName  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "getServiceGroupParameter",
                        "http://org.apache.axis2/xsd",
                        NULL);
                _getServiceGroupParameter->qname = qname;
            

            return _getServiceGroupParameter;
        }

        adb_getServiceGroupParameter_t* AXIS2_CALL
        adb_getServiceGroupParameter_create_with_values(
            const axutil_env_t *env,
                axis2_char_t* _serviceGroupName,
                axis2_char_t* _paramName)
        {
            adb_getServiceGroupParameter_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_getServiceGroupParameter_create(env);

            
              status = adb_getServiceGroupParameter_set_serviceGroupName(
                                     adb_obj,
                                     env,
                                     _serviceGroupName);
              if(status == AXIS2_FAILURE) {
                  adb_getServiceGroupParameter_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_getServiceGroupParameter_set_paramName(
                                     adb_obj,
                                     env,
                                     _paramName);
              if(status == AXIS2_FAILURE) {
                  adb_getServiceGroupParameter_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axis2_char_t* AXIS2_CALL
                adb_getServiceGroupParameter_free_popping_value(
                        adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                        const axutil_env_t *env)
                {
                    axis2_char_t* value;

                    
                    
                    value = _getServiceGroupParameter->property_serviceGroupName;

                    _getServiceGroupParameter->property_serviceGroupName = (axis2_char_t*)NULL;
                    adb_getServiceGroupParameter_free(_getServiceGroupParameter, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_getServiceGroupParameter_free(
                adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                const axutil_env_t *env)
        {
            
            
            return adb_getServiceGroupParameter_free_obj(
                _getServiceGroupParameter,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_getServiceGroupParameter_free_obj(
                adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, AXIS2_FAILURE);

            if (_getServiceGroupParameter->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _getServiceGroupParameter->property_Type);
            }

            adb_getServiceGroupParameter_reset_serviceGroupName(_getServiceGroupParameter, env);
            adb_getServiceGroupParameter_reset_paramName(_getServiceGroupParameter, env);
            
              if(_getServiceGroupParameter->qname)
              {
                  axutil_qname_free (_getServiceGroupParameter->qname, env);
                  _getServiceGroupParameter->qname = NULL;
              }
            

            if(_getServiceGroupParameter)
            {
                AXIS2_FREE(env->allocator, _getServiceGroupParameter);
                _getServiceGroupParameter = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_getServiceGroupParameter_deserialize(
                adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_getServiceGroupParameter_deserialize_obj(
                _getServiceGroupParameter,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_getServiceGroupParameter_deserialize_obj(
                adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
           
             const axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for getServiceGroupParameter : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _getServiceGroupParameter-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for getServiceGroupParameter : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_getServiceGroupParameter-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building serviceGroupName element
                      */
                     
                     
                     
                                   current_node = first_node;
                                   is_early_node_valid = AXIS2_FALSE;
                                   
                                   
                                    while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                    {
                                        current_node = axiom_node_get_next_sibling(current_node, env);
                                    }
                                    if(current_node != NULL)
                                    {
                                        current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                        qname = axiom_element_get_qname(current_element, env, current_node);
                                    }
                                   
                                 element_qname = axutil_qname_create(env, "serviceGroupName", "http://org.apache.axis2/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_getServiceGroupParameter_set_serviceGroupName(_getServiceGroupParameter, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for serviceGroupName ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building paramName element
                      */
                     
                     
                     
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   
                                   if(current_node != NULL && is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, env);
                                       
                                       
                                        while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, env);
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                            qname = axiom_element_get_qname(current_element, env, current_node);
                                        }
                                       
                                   }
                                   is_early_node_valid = AXIS2_FALSE;
                                 
                                 element_qname = axutil_qname_create(env, "paramName", "http://org.apache.axis2/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_getServiceGroupParameter_set_paramName(_getServiceGroupParameter, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for paramName ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_getServiceGroupParameter_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_getServiceGroupParameter_declare_parent_namespaces(
                    adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_getServiceGroupParameter_serialize(
                adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_getServiceGroupParameter_serialize_obj(
                    _getServiceGroupParameter, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_getServiceGroupParameter_serialize_obj(
                adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
                    axis2_char_t *text_value_1;
                    axis2_char_t *text_value_1_temp;
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://org.apache.axis2/xsd",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "getServiceGroupParameter", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_getServiceGroupParameter->is_valid_serviceGroupName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("serviceGroupName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("serviceGroupName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing serviceGroupName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sserviceGroupName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sserviceGroupName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_1 = _getServiceGroupParameter->property_serviceGroupName;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_1_temp = axutil_xml_quote_string(env, text_value_1, AXIS2_TRUE);
                           if (text_value_1_temp)
                           {
                               axutil_stream_write(stream, env, text_value_1_temp, axutil_strlen(text_value_1_temp));
                               AXIS2_FREE(env->allocator, text_value_1_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://org.apache.axis2/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://org.apache.axis2/xsd",
                                            p_prefix));
                       }
                      

                   if (!_getServiceGroupParameter->is_valid_paramName)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("paramName"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("paramName")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing paramName element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sparamName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sparamName>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _getServiceGroupParameter->property_paramName;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_2_temp = axutil_xml_quote_string(env, text_value_2, AXIS2_TRUE);
                           if (text_value_2_temp)
                           {
                               axutil_stream_write(stream, env, text_value_2_temp, axutil_strlen(text_value_2_temp));
                               AXIS2_FREE(env->allocator, text_value_2_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                   if(namespaces)
                   {
                       axutil_hash_index_t *hi;
                       void *val;
                       for (hi = axutil_hash_first(namespaces, env); hi; hi = axutil_hash_next(env, hi)) 
                       {
                           axutil_hash_this(hi, NULL, NULL, &val);
                           AXIS2_FREE(env->allocator, val);
                       }
                       axutil_hash_free(namespaces, env);
                   }
                

            return parent;
        }


        

            /**
             * Getter for serviceGroupName by  Property Number 1
             */
            axis2_char_t* AXIS2_CALL
            adb_getServiceGroupParameter_get_property1(
                adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                const axutil_env_t *env)
            {
                return adb_getServiceGroupParameter_get_serviceGroupName(_getServiceGroupParameter,
                                             env);
            }

            /**
             * getter for serviceGroupName.
             */
            axis2_char_t* AXIS2_CALL
            adb_getServiceGroupParameter_get_serviceGroupName(
                    adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, NULL);
                  

                return _getServiceGroupParameter->property_serviceGroupName;
             }

            /**
             * setter for serviceGroupName
             */
            axis2_status_t AXIS2_CALL
            adb_getServiceGroupParameter_set_serviceGroupName(
                    adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_serviceGroupName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, AXIS2_FAILURE);
                
                if(_getServiceGroupParameter->is_valid_serviceGroupName &&
                        arg_serviceGroupName == _getServiceGroupParameter->property_serviceGroupName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_getServiceGroupParameter_reset_serviceGroupName(_getServiceGroupParameter, env);

                
                if(NULL == arg_serviceGroupName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _getServiceGroupParameter->property_serviceGroupName = (axis2_char_t *)axutil_strdup(env, arg_serviceGroupName);
                        if(NULL == _getServiceGroupParameter->property_serviceGroupName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for serviceGroupName");
                            return AXIS2_FAILURE;
                        }
                        _getServiceGroupParameter->is_valid_serviceGroupName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for serviceGroupName
            */
           axis2_status_t AXIS2_CALL
           adb_getServiceGroupParameter_reset_serviceGroupName(
                   adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, AXIS2_FAILURE);
               

               
            
                
                if(_getServiceGroupParameter->property_serviceGroupName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _getServiceGroupParameter->property_serviceGroupName);
                     _getServiceGroupParameter->property_serviceGroupName = NULL;
                }
            
                
                
                _getServiceGroupParameter->is_valid_serviceGroupName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether serviceGroupName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_getServiceGroupParameter_is_serviceGroupName_nil(
                   adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, AXIS2_TRUE);
               
               return !_getServiceGroupParameter->is_valid_serviceGroupName;
           }

           /**
            * Set serviceGroupName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_getServiceGroupParameter_set_serviceGroupName_nil(
                   adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                   const axutil_env_t *env)
           {
               return adb_getServiceGroupParameter_reset_serviceGroupName(_getServiceGroupParameter, env);
           }

           

            /**
             * Getter for paramName by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_getServiceGroupParameter_get_property2(
                adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                const axutil_env_t *env)
            {
                return adb_getServiceGroupParameter_get_paramName(_getServiceGroupParameter,
                                             env);
            }

            /**
             * getter for paramName.
             */
            axis2_char_t* AXIS2_CALL
            adb_getServiceGroupParameter_get_paramName(
                    adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, NULL);
                  

                return _getServiceGroupParameter->property_paramName;
             }

            /**
             * setter for paramName
             */
            axis2_status_t AXIS2_CALL
            adb_getServiceGroupParameter_set_paramName(
                    adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_paramName)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, AXIS2_FAILURE);
                
                if(_getServiceGroupParameter->is_valid_paramName &&
                        arg_paramName == _getServiceGroupParameter->property_paramName)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_getServiceGroupParameter_reset_paramName(_getServiceGroupParameter, env);

                
                if(NULL == arg_paramName)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _getServiceGroupParameter->property_paramName = (axis2_char_t *)axutil_strdup(env, arg_paramName);
                        if(NULL == _getServiceGroupParameter->property_paramName)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for paramName");
                            return AXIS2_FAILURE;
                        }
                        _getServiceGroupParameter->is_valid_paramName = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for paramName
            */
           axis2_status_t AXIS2_CALL
           adb_getServiceGroupParameter_reset_paramName(
                   adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, AXIS2_FAILURE);
               

               
            
                
                if(_getServiceGroupParameter->property_paramName != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _getServiceGroupParameter->property_paramName);
                     _getServiceGroupParameter->property_paramName = NULL;
                }
            
                
                
                _getServiceGroupParameter->is_valid_paramName = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether paramName is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_getServiceGroupParameter_is_paramName_nil(
                   adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _getServiceGroupParameter, AXIS2_TRUE);
               
               return !_getServiceGroupParameter->is_valid_paramName;
           }

           /**
            * Set paramName to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_getServiceGroupParameter_set_paramName_nil(
                   adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                   const axutil_env_t *env)
           {
               return adb_getServiceGroupParameter_reset_paramName(_getServiceGroupParameter, env);
           }

           

