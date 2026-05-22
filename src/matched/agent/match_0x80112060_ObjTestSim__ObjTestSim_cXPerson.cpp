// 0x80112060 ObjTestSim::ObjTestSim(cXPerson (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 0,0; stw 4,0x0(30); stw 0,0x18(30); mr 4,5; stw 0,0x4(30); bl _s80112060_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80112060_0();
extern "C" void f_80112060() {}
