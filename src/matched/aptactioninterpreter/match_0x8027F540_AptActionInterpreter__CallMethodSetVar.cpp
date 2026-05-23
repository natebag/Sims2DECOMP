// FLAGS: -fno-schedule-insns
// 0x8027F540 AptActionInterpreter__CallMethodSetVar (92B)
typedef unsigned char u8;

extern u8* g_aptGlobal2;

void callMethodAction(u8*, u8*);
void doSetVar2(u8*, u8*);
void reportError2(u8*);

void AptActionInterpreter_CallMethodSetVar(u8* interp, u8* ctx) {
    callMethodAction(interp, ctx);
    doSetVar2(interp, ctx);
    u8* global = g_aptGlobal2;
    if (*(int*)(global + 4) != 0) {
        if (*(int*)(interp) == 0) {
            reportError2(global);
        }
    }
}
