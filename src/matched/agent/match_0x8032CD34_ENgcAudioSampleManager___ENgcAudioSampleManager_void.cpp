// 0x8032CD34 ENgcAudioSampleManager::~ENgcAudioSampleManager(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; mr 11,3; addi 9,9,-15888; stw 9,0xd1c(11); bl _s8032CD34_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032CD34_0();
extern "C" void f_8032CD34() {}
