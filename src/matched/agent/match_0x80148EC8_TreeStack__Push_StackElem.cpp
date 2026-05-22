// 0x80148EC8 TreeStack::Push(StackElem (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 30,4; mr 31,3; mr 29,5; addi 27,1,8; mr 3,30; addi 28,31,8; bl _s80148EC8_0; mr 4,3; mr 3,31; bl _s80148EC8_1; mr 4,30; mr 5,29; stw 3,0x8(1); bl _s80148EC8_2; lwz 30,0x4(28); lwz 0,0xc(28); cmpw 30,0; beq 0f; lwz 0,0x8(1); stw 0,0x0(30); lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 11f; 0:; lwz 0,0x8(31); li 9,1; stw 9,0x10(1); addi 11,1,16; subf 0,0,30; addi 9,1,12; srawi 3,0,2; stw 3,0xc(1); cmplwi 3,1; bge 1f; mr 9,11; 1:; lwz 0,0x0(9); add. 0,3,0; beq 3f; rlwinm 0,0,2,0,29; mr 31,0; cmplwi 0,128; ble 2f; mr 3,31; bl _s80148EC8_3; mr 29,3; b 4f; 2:; mr 3,31; bl _s80148EC8_4; mr 29,3; b 4f; 3:; li 29,0; li 31,0; 4:; lwz 4,0x0(28); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80148EC8_5; add 0,3,30; b 6f; 5:; mr 0,29; 6:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s80148EC8_6; b 10f; 9:; bl _s80148EC8_7; 10:; add 0,31,29; stw 29,0x0(28); stw 0,0xc(28); stw 30,0x4(28); 11:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s80148EC8_0();
extern "C" void _s80148EC8_1();
extern "C" void _s80148EC8_2();
extern "C" void _s80148EC8_3();
extern "C" void _s80148EC8_4();
extern "C" void _s80148EC8_5();
extern "C" void _s80148EC8_6();
extern "C" void _s80148EC8_7();
extern "C" void f_80148EC8() {}
