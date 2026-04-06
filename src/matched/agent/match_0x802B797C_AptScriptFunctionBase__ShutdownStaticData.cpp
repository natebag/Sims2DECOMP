extern void* gScriptFuncData;
extern void* gScriptFuncData2;
extern "C" void cleanupData(void*);
void AptScriptFunctionBase_ShutdownStaticData() {
    if (gScriptFuncData) {
        cleanupData(gScriptFuncData);
    }
    gScriptFuncData2 = 0;
    gScriptFuncData = 0;
}
