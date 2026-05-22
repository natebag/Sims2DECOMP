// 0x8032561C EResourceManager::EResourceManager(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 9,9,-17096; stw 9,0xd1c(30); bl _s8032561C_0; addi 3,30,68; bl _s8032561C_1; mr 4,30; addi 3,30,88; bl _s8032561C_2; addi 3,30,3336; bl _s8032561C_3; li 0,0; mr 3,30; stw 0,0x54(30); stw 0,0x48(30); stw 0,0x50(30); stw 0,0x4c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032561C_0();
extern "C" void _s8032561C_1();
extern "C" void _s8032561C_2();
extern "C" void _s8032561C_3();
extern "C" void f_8032561C() {}
