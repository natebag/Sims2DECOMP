// 0x80113DB0 PassiveInfluenceSystem::PassiveInfluenceSystem(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 28,0x38(1); stw 0,0x4c(1); mr 31,3; li 30,0; stw 30,0x4(31); li 3,12; addi 29,31,8; addi 28,31,16; bl _s80113DB0_0; mr 9,3; stw 9,0x0(9); li 3,12; stw 9,0x4(9); stw 9,0x4(31); stw 30,0x4(29); bl _s80113DB0_1; mr 9,3; stw 9,0x0(9); li 3,12; stw 9,0x4(9); stw 9,0x4(29); stw 30,0x4(28); bl _s80113DB0_2; lwz 0,-31780(13); stw 3,0x0(3); stw 3,0x4(3); cmpwi 0,0; stw 3,0x4(28); bne 0f; stw 31,-31780(13); 0:; mr 3,31; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x38(1); addi 1,1,72"
extern "C" void _s80113DB0_0();
extern "C" void _s80113DB0_1();
extern "C" void _s80113DB0_2();
extern "C" void f_80113DB0() {}
