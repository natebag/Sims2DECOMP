typedef unsigned char u8;

extern u8* g_aptGlobal;

void callFuncAction(u8*, u8*);
void doSetVar(u8*, u8*);
void reportError(u8*);

void AptActionInterpreter_CallFuncSetVar(u8* interp, u8* ctx) {
    callFuncAction(interp, ctx);
    doSetVar(interp, ctx);
    u8* global = g_aptGlobal;
    if (*(int*)(global + 4) != 0) {
        if (*(int*)(interp) == 0) {
            reportError(global);
        }
    }
}
