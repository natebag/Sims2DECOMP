// 0x80058D2C OptionsRecon::ReadIn(int) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); mr 30,4; mr 28,3; bl _s80058D2C_0; li 25,0; li 7,0; li 4,8192; li 5,32; li 6,0; bl _s80058D2C_1; li 26,8192; mr 31,3; li 4,0; addi 3,31,8; li 5,8184; bl _s80058D2C_2; lis 9,-32697; addi 27,9,24012; b 3f; 0:; addi 30,31,8; li 4,8184; mr 3,30; bl _s80058D2C_3; lwz 0,0x0(31); cmpw 0,3; bne 2f; li 3,70; li 4,9; li 5,12; li 6,0; bl _s80058D2C_4; lwz 0,0x4(31); cmpw 0,3; beq 1f; lwz 0,0x338(27); cmpwi 0,0; beq 2f; 1:; stw 30,0xc(1); mr 3,28; stw 25,0x10(1); addi 4,1,8; stw 26,0x8(1); li 5,0; addi 6,1,24; bl _s80058D2C_5; b 4f; 2:; li 29,-4; b 4f; 3:; mr 5,30; mr 3,31; li 4,8192; bl _s80058D2C_6; mr 29,3; cmpwi 29,1; beq 0b; 4:; bl _s80058D2C_7; mr 4,31; bl _s80058D2C_8; lwz 3,-26524(13); lwz 9,0x20(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,29; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s80058D2C_0();
extern "C" void _s80058D2C_1();
extern "C" void _s80058D2C_2();
extern "C" void _s80058D2C_3();
extern "C" void _s80058D2C_4();
extern "C" void _s80058D2C_5();
extern "C" void _s80058D2C_6();
extern "C" void _s80058D2C_7();
extern "C" void _s80058D2C_8();
extern "C" void f_80058D2C() {}
