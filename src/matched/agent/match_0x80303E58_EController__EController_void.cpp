// 0x80303E58 EController::EController(void) (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,-21000; addi 11,13,-21316; stw 9,0x208(31); li 6,32; li 0,0; li 10,-1; lwz 9,0x0(11); mtspr 9,6; addi 8,31,12; li 7,0; stw 9,0x0(31); addi 9,9,1; stw 9,0x0(11); stw 0,0x4(31); stw 10,0x8(31); 0:; stw 7,0x0(8); stw 7,0x4(8); stw 7,0x8(8); addi 8,8,12; bdnz 0b; li 0,0; li 9,10; li 11,3; li 10,1; stb 9,0x1d8(31); li 3,132; stb 11,0x1d9(31); stw 0,0x200(31); stw 10,0x204(31); stw 0,0x1a4(31); stw 0,0x1a8(31); stw 0,0x1ac(31); stw 0,0x1b0(31); stw 0,0x1b4(31); stw 0,0x1fc(31); bl _s80303E58_0; mr 30,3; li 4,1; bl _s80303E58_1; stw 30,0x1fc(31); li 3,132; bl _s80303E58_2; mr 30,3; li 4,1; bl _s80303E58_3; stw 30,0x200(31); addi 6,31,440; li 5,0; addi 7,31,404; addi 8,31,408; li 0,1; addi 10,31,400; li 11,0; addi 9,31,396; 1:; stw 5,0x0(9); stwx 0,11,8; addi 9,9,4; stwx 0,11,7; cmpw 9,10; addi 11,11,8; ble 1b; li 0,32; mr 11,6; mtspr 9,0; li 9,0; 2:; lbz 0,0x1d8(31); stbx 0,11,9; addi 9,9,1; bdnz 2b; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80303E58_0();
extern "C" void _s80303E58_1();
extern "C" void _s80303E58_2();
extern "C" void _s80303E58_3();
extern "C" void f_80303E58() {}
