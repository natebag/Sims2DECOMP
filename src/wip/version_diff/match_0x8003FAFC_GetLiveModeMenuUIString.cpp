// 0x8003FAFC EGlobal::GetLiveModeMenuUIString (16b)
// FLAGS: -fno-schedule-insns2

// SDA global at r13-24988
extern char g_liveModeMenuUIString[4];

void EGlobal_GetLiveModeMenuUIString(void** out) {
    register char* global asm("r0") = *(char**)g_liveModeMenuUIString;
    register void** dst asm("r9") = out;
    *(char**)dst = global;
}

extern "C" void _ZN7EGlobal23GetLiveModeMenuUIStringEPc(void** out) {
    EGlobal_GetLiveModeMenuUIString(out);
}
