// 0x802530AC OSGetGbsMode (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,3,-24704; bl _s802530AC_0; lwz 0,0x48(31); addi 4,31,72; cmpwi 0,0; beq 0f; bl _s802530AC_1; li 3,0; b 1f; 0:; stw 3,0x44(31); li 0,1; addi 3,31,20; stw 0,0x0(4); 1:; lhz 31,0x28(3); li 3,0; li 4,20; bl _s802530AC_2; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802530AC_0();
extern "C" void _s802530AC_1();
extern "C" void _s802530AC_2();
extern "C" void f_802530AC() {}
