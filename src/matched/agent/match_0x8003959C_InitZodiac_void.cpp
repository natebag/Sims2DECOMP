// 0x8003959C InitZodiac(void) (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 28,0x40(1); stw 0,0x54(1); lwz 0,-32520(13); cmpwi 0,0; bne 0f; lis 30,-32697; lis 5,-32707; addi 3,1,8; addi 5,5,5936; addi 4,30,24012; lis 28,-32697; crxor 6,6,6; bl _s8003959C_0; addi 29,28,23380; lwz 0,0x8(1); lis 5,-32707; addi 3,1,12; addi 5,5,5952; stw 0,0x5b54(28); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_1; lwz 0,0xc(1); lis 5,-32707; addi 3,1,16; addi 5,5,5968; stw 0,0x4(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_2; lwz 0,0x10(1); lis 5,-32707; addi 3,1,20; addi 5,5,5984; stw 0,0x8(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_3; lwz 0,0x14(1); lis 5,-32707; addi 3,1,24; addi 5,5,6000; stw 0,0xc(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_4; lwz 0,0x18(1); lis 5,-32707; addi 3,1,28; addi 5,5,6012; stw 0,0x10(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_5; lwz 0,0x1c(1); lis 5,-32707; addi 3,1,32; addi 5,5,6028; stw 0,0x14(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_6; lwz 0,0x20(1); lis 5,-32707; addi 3,1,36; addi 5,5,6044; stw 0,0x18(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_7; lwz 0,0x24(1); lis 5,-32707; addi 3,1,40; addi 5,5,6060; stw 0,0x1c(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_8; lwz 0,0x28(1); lis 5,-32707; addi 3,1,44; addi 5,5,6080; stw 0,0x20(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_9; lwz 0,0x2c(1); lis 5,-32707; addi 3,1,48; addi 5,5,6100; stw 0,0x24(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_10; lwz 0,0x30(1); lis 5,-32707; addi 3,1,52; addi 5,5,6116; stw 0,0x28(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_11; lwz 0,0x34(1); lis 5,-32707; addi 5,5,6132; addi 3,1,56; stw 0,0x2c(29); addi 4,30,24012; crxor 6,6,6; bl _s8003959C_12; lwz 0,0x38(1); lis 5,-32707; addi 4,30,24012; addi 5,5,6148; stw 0,-25028(13); addi 3,1,60; crxor 6,6,6; bl _s8003959C_13; lwz 9,0x3c(1); li 0,1; stw 0,-32520(13); stw 9,-25024(13); 0:; lwz 3,-32520(13); lwz 0,0x54(1); mtspr 8,0; lmw 28,0x40(1); addi 1,1,80"
extern "C" void _s8003959C_0();
extern "C" void _s8003959C_1();
extern "C" void _s8003959C_2();
extern "C" void _s8003959C_3();
extern "C" void _s8003959C_4();
extern "C" void _s8003959C_5();
extern "C" void _s8003959C_6();
extern "C" void _s8003959C_7();
extern "C" void _s8003959C_8();
extern "C" void _s8003959C_9();
extern "C" void _s8003959C_10();
extern "C" void _s8003959C_11();
extern "C" void _s8003959C_12();
extern "C" void _s8003959C_13();
extern "C" void f_8003959C() {}
