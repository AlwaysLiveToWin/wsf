/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.axis2.wsdl.databinding;

import javax.xml.namespace.QName;

public class CDefaultTypeMapper extends TypeMappingAdapter {
    private String defaultStructName = "axiom_node_t*";

    public CDefaultTypeMapper() {
    }

    /**
     * Gets the type mapping name. always returns the default mapping
     *
     * @see TypeMapper#getTypeMappingName(javax.xml.namespace.QName)
     */
    public String getTypeMappingName(QName qname) {

        if ((qname != null)) {
            return defaultStructName;
        } else {
            return null;
        }

    }
}
