// 0x8032CC80 EAudioSampleManager::EAudioSampleManager(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8032CC80_0; lis 9,-32697; mr 3,30; addi 9,9,-15800; stw 9,0xd1c(30); stw 30,-22572(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032CC80_0();
extern "C" void f_8032CC80() {}
