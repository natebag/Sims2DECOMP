// 0x802C704C EFileSystem::Init(EFile::DeviceType) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x14(31); cmpwi 0,0; bne 1f; lwz 0,-26880(13); cmpwi 0,0; bne 0f; bl _s802C704C_0; 0:; li 0,1; stw 30,0x10(31); stw 0,0x14(31); li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C704C_0();
extern "C" void f_802C704C() {}
