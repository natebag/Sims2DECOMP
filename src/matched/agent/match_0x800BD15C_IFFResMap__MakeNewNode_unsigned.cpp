// 0x800BD15C IFFResMap::MakeNewNode(unsigned (792 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 23,0x6c(1); stw 0,0x94(1); addi 27,1,8; li 5,1; bl _s800BD15C_0; li 0,-1; mr 26,3; stw 0,0x8(1); addi 31,1,24; li 9,0; sth 0,0xa(27); stw 0,0x4(27); mr 3,31; sth 0,0x8(27); addi 4,1,32; stw 9,0xc(27); li 5,64; bl _s800BD15C_1; lwz 11,0x4(26); lwz 0,0xc(26); cmpw 11,0; beq 0f; lwz 0,0x8(1); addi 30,11,16; addi 4,11,24; li 5,64; stw 0,0x0(11); mr 3,30; lwz 0,0x4(27); stw 0,0x4(11); lhz 9,0x8(27); sth 9,0x8(11); lhz 0,0xa(27); sth 0,0xa(11); lwz 9,0xc(27); stw 9,0xc(11); bl _s800BD15C_2; mr 3,30; mr 4,31; li 5,-1; bl _s800BD15C_3; lwz 9,0x4(26); addi 9,9,88; stw 9,0x4(26); b 15f; 0:; lwz 0,0x0(26); mr 25,11; lis 9,-17874; li 11,1; ori 9,9,35747; subf 0,0,25; mullw 0,0,9; stw 11,0x64(1); addi 10,1,100; addi 11,1,96; srawi 9,0,3; stw 9,0x60(1); cmplwi 9,1; bge 1f; mr 11,10; 1:; lwz 0,0x0(11); add. 0,9,0; beq 3f; mulli 0,0,88; mr 24,0; cmplwi 0,128; ble 2f; mr 3,24; bl _s800BD15C_4; b 4f; 2:; mr 3,24; bl _s800BD15C_5; b 4f; 3:; li 3,0; li 24,0; 4:; mr 28,3; lwz 31,0x0(26); mr 23,28; cmpw 31,25; beq 6f; 5:; lwz 0,0x0(31); addi 30,28,16; addi 4,28,24; li 5,64; stw 0,0x0(28); mr 3,30; addi 29,31,16; lwz 0,0x4(31); stw 0,0x4(28); lhz 9,0x8(31); sth 9,0x8(28); lhz 0,0xa(31); sth 0,0xa(28); lwz 9,0xc(31); addi 31,31,88; stw 9,0xc(28); bl _s800BD15C_6; addi 28,28,88; mr 3,30; mr 4,29; li 5,-1; bl _s800BD15C_7; cmpw 31,25; bne 5b; 6:; lwz 0,0x64(1); cmpwi 0,1; bne 7f; lwz 0,0x0(27); addi 30,28,16; addi 4,28,24; li 5,64; stw 0,0x0(28); mr 3,30; addi 29,27,16; lwz 0,0x4(27); stw 0,0x4(28); lhz 9,0x8(27); sth 9,0x8(28); lhz 0,0xa(27); sth 0,0xa(28); lwz 9,0xc(27); stw 9,0xc(28); bl _s800BD15C_8; addi 28,28,88; mr 3,30; mr 4,29; li 5,-1; bl _s800BD15C_9; b 10f; 7:; mr 29,28; mr. 31,0; beq 9f; 8:; lwz 0,0x0(27); addi 30,29,16; addi 4,29,24; li 5,64; stw 0,0x0(29); mr 3,30; lwz 0,0x4(27); stw 0,0x4(29); lhz 9,0x8(27); sth 9,0x8(29); lhz 0,0xa(27); sth 0,0xa(29); lwz 9,0xc(27); stw 9,0xc(29); bl _s800BD15C_10; addi 29,29,88; mr 3,30; addi 4,27,16; li 5,-1; bl _s800BD15C_11; addic. 31,31,-1; bne 8b; 9:; mr 28,29; 10:; lwz 11,0x4(26); lwz 9,0x0(26); lwz 0,0xc(26); cmpw 9,11; beq 12f; 11:; addi 9,9,88; cmpw 9,11; bne 11b; 12:; lwz 3,0x0(26); lis 9,-17874; ori 9,9,35747; subf 0,3,0; cmpwi 3,0; mullw 0,0,9; srawi 0,0,3; beq 14f; mulli 4,0,88; cmplwi 4,128; ble 13f; bl _s800BD15C_12; b 14f; 13:; bl _s800BD15C_13; 14:; add 0,24,23; stw 23,0x0(26); stw 28,0x4(26); stw 0,0xc(26); 15:; lwz 3,0x0(26); lis 9,-17874; lwz 0,0x4(26); ori 9,9,35747; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 0,0,88; add 3,3,0; addi 3,3,-88; lwz 0,0x94(1); mtspr 8,0; lmw 23,0x6c(1); addi 1,1,144"
extern "C" void _s800BD15C_0();
extern "C" void _s800BD15C_1();
extern "C" void _s800BD15C_2();
extern "C" void _s800BD15C_3();
extern "C" void _s800BD15C_4();
extern "C" void _s800BD15C_5();
extern "C" void _s800BD15C_6();
extern "C" void _s800BD15C_7();
extern "C" void _s800BD15C_8();
extern "C" void _s800BD15C_9();
extern "C" void _s800BD15C_10();
extern "C" void _s800BD15C_11();
extern "C" void _s800BD15C_12();
extern "C" void _s800BD15C_13();
extern "C" void f_800BD15C() {}
