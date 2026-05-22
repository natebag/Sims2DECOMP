// 0x801FF838 PSETarget::PushAptButtonFilters(void) (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; mr 28,3; lwz 0,0x5c70(9); li 27,1; cmpwi 0,0; beq 0f; li 27,2; 0:; li 30,0; cmpw 30,27; bge 2f; lis 9,-32697; addi 31,28,140; addi 29,9,24012; 1:; lwz 5,0x7c(28); mr 4,30; lwz 3,0xb4(29); bl _s801FF838_0; mr 5,3; mr 4,30; stw 5,0x0(31); li 6,1; lwz 3,0xb4(29); bl _s801FF838_1; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,2; bl _s801FF838_2; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,3; bl _s801FF838_3; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,4; bl _s801FF838_4; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,5; bl _s801FF838_5; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,6; bl _s801FF838_6; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,17; bl _s801FF838_7; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,19; bl _s801FF838_8; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,20; bl _s801FF838_9; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,21; bl _s801FF838_10; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,22; bl _s801FF838_11; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,23; bl _s801FF838_12; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,7; bl _s801FF838_13; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,24; bl _s801FF838_14; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,25; bl _s801FF838_15; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,13; bl _s801FF838_16; lwz 5,0x0(31); mr 4,30; lwz 3,0xb4(29); li 6,14; addi 30,30,1; addi 31,31,4; bl _s801FF838_17; cmpw 30,27; blt 1b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801FF838_0();
extern "C" void _s801FF838_1();
extern "C" void _s801FF838_2();
extern "C" void _s801FF838_3();
extern "C" void _s801FF838_4();
extern "C" void _s801FF838_5();
extern "C" void _s801FF838_6();
extern "C" void _s801FF838_7();
extern "C" void _s801FF838_8();
extern "C" void _s801FF838_9();
extern "C" void _s801FF838_10();
extern "C" void _s801FF838_11();
extern "C" void _s801FF838_12();
extern "C" void _s801FF838_13();
extern "C" void _s801FF838_14();
extern "C" void _s801FF838_15();
extern "C" void _s801FF838_16();
extern "C" void _s801FF838_17();
extern "C" void f_801FF838() {}
