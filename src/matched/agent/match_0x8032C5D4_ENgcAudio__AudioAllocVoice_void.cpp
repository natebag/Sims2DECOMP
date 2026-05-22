// 0x8032C5D4 ENgcAudio::AudioAllocVoice(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 3,32; bl _s8032C5D4_0; mr 30,3; li 0,-1; stw 0,0x8(30); bl _s8032C5D4_1; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032C5D4_0();
extern "C" void _s8032C5D4_1();
extern "C" void f_8032C5D4() {}
