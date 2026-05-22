// 0x803A1000 StartScreenStartState::Shutdown(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; lis 29,-32692; lis 4,32602; addi 3,29,-17444; ori 4,4,48173; li 30,0; bl _s803A1000_0; stw 30,0x1c(28); lis 3,-32697; addi 3,3,23428; bl _s803A1000_1; mr 4,3; addi 3,29,-17444; bl _s803A1000_2; stw 30,0x20(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803A1000_0();
extern "C" void _s803A1000_1();
extern "C" void _s803A1000_2();
extern "C" void f_803A1000() {}
