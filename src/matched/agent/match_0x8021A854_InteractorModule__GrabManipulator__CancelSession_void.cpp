// 0x8021A854 InteractorModule::GrabManipulator::CancelSession(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); lis 9,-32697; addi 28,1,8; addi 9,9,-31496; li 0,3; stw 9,0x8(28); mr 29,3; stw 0,0x8(1); addi 9,29,172; mr 3,28; lis 30,-32697; lwz 0,0x8(9); addi 30,30,-32168; stw 0,0x4(28); lwz 0,0xc(9); mtspr 8,0; blrl; addi 3,29,100; bl _s8021A854_0; mr 3,29; li 4,1; bl _s8021A854_1; stw 30,0x8(28); lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s8021A854_0();
extern "C" void _s8021A854_1();
extern "C" void f_8021A854() {}
