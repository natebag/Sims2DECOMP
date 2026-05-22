// 0x8014CA5C int (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s8014CA5C_0; addi 3,1,8; li 4,2; bl _s8014CA5C_1; stw 30,0x30(31); li 3,12; bl _s8014CA5C_2; mr 4,24; mr 5,26; bl _s8014CA5C_3; stw 3,0x3c(31); li 3,12; bl _s8014CA5C_4; mr 4,24; mr 5,26; bl _s8014CA5C_5; stw 3,0x40(31); stw 26,0x18(31); li 3,1; stw 24,0x14(31); lwz 0,0x54(1); mtspr 8,0; lmw 20,0x20(1); addi 1,1,80"
extern "C" void _s8014CA5C_0();
extern "C" void _s8014CA5C_1();
extern "C" void _s8014CA5C_2();
extern "C" void _s8014CA5C_3();
extern "C" void _s8014CA5C_4();
extern "C" void _s8014CA5C_5();
extern "C" void f_8014CA5C() {}
