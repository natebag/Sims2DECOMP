// 0x8032C614 ENgcAudio::FreeVoice(EVoice (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0x0(3); mr 30,4; lha 0,0xa0(9); lwz 9,0xa4(9); add 3,3,0; mtspr 8,9; blrl; mr 3,30; bl _s8032C614_0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032C614_0();
extern "C" void f_8032C614() {}
