// 0x80218F3C InteractorModule::ObjectManipulator::ObjectManipulator(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80218F3C_0; lis 9,-32697; addi 3,30,100; addi 9,9,-31472; stw 9,0x5c(30); bl _s80218F3C_1; lis 9,-32704; lis 11,-32704; lfs f0,-9880(9); addi 10,30,152; lfs f13,-9876(11); li 0,1; stfs f0,0x4(10); mr 3,30; stfs f0,0x8(10); stfs f0,0x98(30); stfs f13,0xa4(30); stw 0,0xa8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80218F3C_0();
extern "C" void _s80218F3C_1();
extern "C" void f_80218F3C() {}
