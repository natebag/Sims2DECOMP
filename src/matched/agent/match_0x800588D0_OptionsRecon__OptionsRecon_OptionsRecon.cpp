// 0x800588D0 OptionsRecon::OptionsRecon(OptionsRecon (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; addi 4,30,96; li 5,32; addi 3,30,88; bl _s800588D0_0; addi 4,30,168; li 5,32; addi 3,30,160; bl _s800588D0_1; mr 4,29; mr 3,30; bl _s800588D0_2; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800588D0_0();
extern "C" void _s800588D0_1();
extern "C" void _s800588D0_2();
extern "C" void f_800588D0() {}
