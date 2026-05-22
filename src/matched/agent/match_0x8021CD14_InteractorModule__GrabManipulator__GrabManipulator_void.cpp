// 0x8021CD14 InteractorModule::GrabManipulator::GrabManipulator(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8021CD14_0; lis 9,-32697; lis 11,-32698; addi 9,9,-31704; addi 10,30,172; stw 9,0x5c(30); addi 11,11,29056; stw 11,0x10(10); lis 9,-32704; addi 11,30,200; li 8,2; lfs f0,-9716(9); li 7,0; li 0,0; mr 3,30; stfs f0,0x4(11); stfs f0,0x8(11); stfs f0,0xc8(30); stw 8,0xac(30); stw 0,0x18(10); sth 7,0x14(10); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8021CD14_0();
extern "C" void f_8021CD14() {}
