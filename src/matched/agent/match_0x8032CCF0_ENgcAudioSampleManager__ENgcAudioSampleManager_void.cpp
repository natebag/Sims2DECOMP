// 0x8032CCF0 ENgcAudioSampleManager::ENgcAudioSampleManager(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8032CCF0_0; lis 9,-32697; li 0,1; addi 9,9,-15888; stw 0,0x54(30); stw 9,0xd1c(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032CCF0_0();
extern "C" void f_8032CCF0() {}
