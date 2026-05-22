// 0x803570B4 FrameEffect::IsEffectRamping(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); li 3,0; cmpwi 0,2; beq 0f; cmpwi 0,8; bnelr; 0:; li 3,1"
extern "C" int f_803570B4() {}
