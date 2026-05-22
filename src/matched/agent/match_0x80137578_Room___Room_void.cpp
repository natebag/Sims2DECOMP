// 0x80137578 Room::~Room(void) (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; bl _s80137578_0; lwz 11,0x24(29); addi 8,29,36; lwz 0,0x4(8); mr 9,11; addi 10,29,36; addi 31,29,20; cmpw 11,0; addi 28,29,4; beq 1f; 0:; addi 9,9,20; cmpw 9,0; bne 0b; 1:; stw 11,0x4(8); lwz 0,0x4(10); lwz 9,0x24(29); cmpw 9,0; beq 3f; 2:; addi 9,9,20; cmpw 9,0; bne 2b; 3:; lwz 3,0x0(10); cmpwi 3,0; beq 5f; lwz 0,0xc(10); lis 9,-13108; ori 9,9,52429; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 4f; bl _s80137578_1; b 5f; 4:; bl _s80137578_2; 5:; lwz 0,0x4(31); lwz 9,0x14(29); cmpw 9,0; beq 7f; 6:; addi 9,9,12; cmpw 9,0; bne 6b; 7:; lwz 3,0x0(31); cmpwi 3,0; beq 9f; lwz 0,0xc(31); lis 9,-21846; ori 9,9,43691; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,12; cmplwi 4,128; ble 8f; bl _s80137578_3; b 9f; 8:; bl _s80137578_4; 9:; lwz 30,0x4(28); lwz 31,0x4(29); cmpw 31,30; beq 11f; 10:; mr 3,31; li 4,2; bl _s80137578_5; addi 31,31,3; cmpw 31,30; bne 10b; 11:; lwz 3,0x0(28); cmpwi 3,0; beq 13f; lwz 0,0xc(28); subf 4,3,0; cmplwi 4,128; ble 12f; bl _s80137578_6; b 13f; 12:; bl _s80137578_7; 13:; andi. 0,27,1; beq 14f; mr 3,29; bl _s80137578_8; 14:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80137578_0();
extern "C" void _s80137578_1();
extern "C" void _s80137578_2();
extern "C" void _s80137578_3();
extern "C" void _s80137578_4();
extern "C" void _s80137578_5();
extern "C" void _s80137578_6();
extern "C" void _s80137578_7();
extern "C" void _s80137578_8();
extern "C" void f_80137578() {}
