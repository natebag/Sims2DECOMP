// 0x8013D8D0 TryCatExtension(StackString<260> (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1120(1); mfspr 0,8; stmw 27,0x44c(1); stw 0,0x464(1); lwz 0,0x0(4); mr 28,3; cmpwi 0,0; beq 1f; addi 30,4,4; mr 3,30; bl _s8013D8D0_0; cmpwi 3,1; ble 1f; mr 3,30; li 4,0; bl _s8013D8D0_1; cmpwi 3,46; bne 1f; addi 31,1,8; li 5,260; addi 4,31,8; mr 3,31; bl _s8013D8D0_2; addi 29,1,280; addi 27,1,552; mr 4,30; mr 3,31; li 5,-1; bl _s8013D8D0_3; addi 4,1,288; addi 3,1,280; li 5,260; bl _s8013D8D0_4; addi 4,1,560; addi 3,1,552; li 5,260; bl _s8013D8D0_5; mr 3,28; mr 4,27; mr 5,29; bl _s8013D8D0_6; mr 3,29; bl _s8013D8D0_7; cmpwi 3,0; ble 0f; mr 3,29; mr 4,31; bl _s8013D8D0_8; subfic 0,3,0; adde 3,0,3; b 2f; 0:; addi 3,1,824; addi 4,1,832; li 5,260; mr 30,3; bl _s8013D8D0_9; mr 3,27; mr 4,30; bl _s8013D8D0_10; mr 3,30; bl _s8013D8D0_11; cmpwi 3,0; beq 1f; mr 4,27; mr 3,28; bl _s8013D8D0_12; mr 3,28; mr 4,31; li 5,-1; bl _s8013D8D0_13; li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x464(1); mtspr 8,0; lmw 27,0x44c(1); addi 1,1,1120"
extern "C" void _s8013D8D0_0();
extern "C" void _s8013D8D0_1();
extern "C" void _s8013D8D0_2();
extern "C" void _s8013D8D0_3();
extern "C" void _s8013D8D0_4();
extern "C" void _s8013D8D0_5();
extern "C" void _s8013D8D0_6();
extern "C" void _s8013D8D0_7();
extern "C" void _s8013D8D0_8();
extern "C" void _s8013D8D0_9();
extern "C" void _s8013D8D0_10();
extern "C" void _s8013D8D0_11();
extern "C" void _s8013D8D0_12();
extern "C" void _s8013D8D0_13();
extern "C" void f_8013D8D0() {}
