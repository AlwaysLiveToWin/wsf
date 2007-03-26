/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Rhino code, released
 * May 6, 1999.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1997-2000
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Igor Bukanov
 *
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU General Public License Version 2 or later (the "GPL"), in which
 * case the provisions of the GPL are applicable instead of those above. If
 * you wish to allow use of your version of this file only under the terms of
 * the GPL and not to allow others to use your version of this file under the
 * MPL, indicate your decision by deleting the provisions above and replacing
 * them with the notice and other provisions required by the GPL. If you do
 * not delete the provisions above, a recipient may use your version of this
 * file under either the MPL or the GPL.
 *
 * ***** END LICENSE BLOCK ***** */
package org.mozilla.javascript.xmlimpl;

import org.mozilla.javascript.Context;
import org.mozilla.javascript.IdFunctionObject;
import org.mozilla.javascript.ScriptRuntime;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.ScriptableObject;
import org.mozilla.javascript.Undefined;

class XMLCtor extends IdFunctionObject {
    static final long serialVersionUID = -8708195078359817341L;

    private static final Object XMLCTOR_TAG = new Object();

    private XMLLibImpl lib;

    XMLCtor(XML xml, Object tag, int id, int arity) {
        super(xml, tag, id, arity);
        this.lib = xml.lib;
        activatePrototypeMap(XMLCtor.MAX_FUNCTION_ID);
    }

    private void writeSetting(Scriptable target) {
        for (int i = 1; i <= XMLCtor.MAX_INSTANCE_ID; ++i) {
            int id = super.getMaxInstanceId() + i;
            String name = getInstanceIdName(id);
            Object value = getInstanceIdValue(id);
            ScriptableObject.putProperty(target, name, value);
        }
    }

    private void readSettings(Scriptable source) {
        for (int i = 1; i <= XMLCtor.MAX_INSTANCE_ID; ++i) {
            int id = super.getMaxInstanceId() + i;
            String name = getInstanceIdName(id);
            Object value = ScriptableObject.getProperty(source, name);
            if (value == ScriptableObject.NOT_FOUND) {
                continue;
            }
            switch (i) {
                case XMLCtor.Id_ignoreComments:
                case XMLCtor.Id_ignoreProcessingInstructions:
                case XMLCtor.Id_ignoreWhitespace:
                case XMLCtor.Id_prettyPrinting:
                    if (!(value instanceof Boolean)) {
                        continue;
                    }
                    break;
                case XMLCtor.Id_prettyIndent:
                    if (!(value instanceof Number)) {
                        continue;
                    }
                    break;
                default:
                    throw new IllegalStateException();
            }
            setInstanceIdValue(id, value);
        }
    }

    private static final int
            Id_ignoreComments = 1,
            Id_ignoreProcessingInstructions = 2,
            Id_ignoreWhitespace = 3,
            Id_prettyIndent = 4,
            Id_prettyPrinting = 5,

            MAX_INSTANCE_ID = 5;

    protected int getMaxInstanceId() {
        return super.getMaxInstanceId() + XMLCtor.MAX_INSTANCE_ID;
    }

    protected int findInstanceIdInfo(String s) {
        int id;
        id = 0;
        String X = null;
        int c;
        L:
        switch (s.length()) {
            case 12:
                X = "prettyIndent";
                id = XMLCtor.Id_prettyIndent;
                break L;
            case 14:
                c = s.charAt(0);
                if (c == 'i') {
                    X = "ignoreComments";
                    id = XMLCtor.Id_ignoreComments;
                } else if (c == 'p') {
                    X = "prettyPrinting";
                    id = XMLCtor.Id_prettyPrinting;
                }
                break L;
            case 16:
                X = "ignoreWhitespace";
                id = XMLCtor.Id_ignoreWhitespace;
                break L;
            case 28:
                X = "ignoreProcessingInstructions";
                id = XMLCtor.Id_ignoreProcessingInstructions;
                break L;
        }
        if (X != null && X != s && !X.equals(s)) id = 0;

        if (id == 0) return super.findInstanceIdInfo(s);

        int attr;
        switch (id) {
            case XMLCtor.Id_ignoreComments:
            case XMLCtor.Id_ignoreProcessingInstructions:
            case XMLCtor.Id_ignoreWhitespace:
            case XMLCtor.Id_prettyIndent:
            case XMLCtor.Id_prettyPrinting:
                attr = PERMANENT | DONTENUM;
                break;
            default:
                throw new IllegalStateException();
        }
        return instanceIdInfo(attr, super.getMaxInstanceId() + id);
    }

    protected String getInstanceIdName(int id) {
        switch (id - super.getMaxInstanceId()) {
            case XMLCtor.Id_ignoreComments:
                return "ignoreComments";
            case XMLCtor.Id_ignoreProcessingInstructions:
                return "ignoreProcessingInstructions";
            case XMLCtor.Id_ignoreWhitespace:
                return "ignoreWhitespace";
            case XMLCtor.Id_prettyIndent:
                return "prettyIndent";
            case XMLCtor.Id_prettyPrinting:
                return "prettyPrinting";
        }
        return super.getInstanceIdName(id);
    }

    protected Object getInstanceIdValue(int id) {
        switch (id - super.getMaxInstanceId()) {
            case XMLCtor.Id_ignoreComments:
                return ScriptRuntime.wrapBoolean(lib.ignoreComments);
            case XMLCtor.Id_ignoreProcessingInstructions:
                return ScriptRuntime.wrapBoolean(lib.ignoreProcessingInstructions);
            case XMLCtor.Id_ignoreWhitespace:
                return ScriptRuntime.wrapBoolean(lib.ignoreWhitespace);
            case XMLCtor.Id_prettyIndent:
                return ScriptRuntime.wrapInt(lib.prettyIndent);
            case XMLCtor.Id_prettyPrinting:
                return ScriptRuntime.wrapBoolean(lib.prettyPrinting);
        }
        return super.getInstanceIdValue(id);
    }

    protected void setInstanceIdValue(int id, Object value) {
        switch (id - super.getMaxInstanceId()) {
            case XMLCtor.Id_ignoreComments:
                lib.ignoreComments = ScriptRuntime.toBoolean(value);
                return;
            case XMLCtor.Id_ignoreProcessingInstructions:
                lib.ignoreProcessingInstructions = ScriptRuntime.toBoolean(value);
                return;
            case XMLCtor.Id_ignoreWhitespace:
                lib.ignoreWhitespace = ScriptRuntime.toBoolean(value);
                return;
            case XMLCtor.Id_prettyIndent:
                lib.prettyIndent = ScriptRuntime.toInt32(value);
                return;
            case XMLCtor.Id_prettyPrinting:
                lib.prettyPrinting = ScriptRuntime.toBoolean(value);
                return;
        }
        super.setInstanceIdValue(id, value);
    }

    private static final int
            Id_defaultSettings = 1,
            Id_settings = 2,
            Id_setSettings = 3,
            MAX_FUNCTION_ID = 3;

    protected int findPrototypeId(String s) {
        int id;
        id = 0;
        String X = null;
        int s_length = s.length();
        if (s_length == 8) {
            X = "settings";
            id = XMLCtor.Id_settings;
        } else if (s_length == 11) {
            X = "setSettings";
            id = XMLCtor.Id_setSettings;
        } else if (s_length == 15) {
            X = "defaultSettings";
            id = XMLCtor.Id_defaultSettings;
        }
        if (X != null && X != s && !X.equals(s)) id = 0;
        return id;
    }

    protected void initPrototypeId(int id) {
        String s;
        int arity;
        switch (id) {
            case XMLCtor.Id_defaultSettings:
                arity = 0;
                s = "defaultSettings";
                break;
            case XMLCtor.Id_settings:
                arity = 0;
                s = "settings";
                break;
            case XMLCtor.Id_setSettings:
                arity = 1;
                s = "setSettings";
                break;
            default:
                throw new IllegalArgumentException(String.valueOf(id));
        }
        initPrototypeMethod(XMLCtor.XMLCTOR_TAG, id, s, arity);
    }

    public Object execIdCall(IdFunctionObject f, Context cx, Scriptable scope,
                             Scriptable thisObj, Object[] args) {
        if (!f.hasTag(XMLCtor.XMLCTOR_TAG)) {
            return super.execIdCall(f, cx, scope, thisObj, args);
        }
        int id = f.methodId();
        switch (id) {
            case XMLCtor.Id_defaultSettings: {
                lib.defaultSettings();
                Scriptable obj = cx.newObject(scope);
                writeSetting(obj);
                return obj;
            }
            case XMLCtor.Id_settings: {
                Scriptable obj = cx.newObject(scope);
                writeSetting(obj);
                return obj;
            }
            case XMLCtor.Id_setSettings: {
                Scriptable obj = null;
                if (args.length == 0
                        || args[0] == null
                        || args[0] == Undefined.instance) {
                    lib.defaultSettings();
                } else if (args[0] instanceof Scriptable) {
                    readSettings((Scriptable) args[0]);
                }
                return Undefined.instance;
            }
        }
        throw new IllegalArgumentException(String.valueOf(id));
    }
}
