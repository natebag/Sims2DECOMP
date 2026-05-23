// 0x8003FBEC EGlobal::GetScriptSubstitutionString(char*) (16B)
extern char* g_scriptSubStr;  // SDA

char* EGlobal__GetScriptSubstitutionString(char** out) {
    *out = g_scriptSubStr;
    return (char*)out;
}
