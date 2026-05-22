// 0x80048590 ObjectList::AddObject(cXObject (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); stw 4,0x8(1); mr 31,3; lwz 0,0x4(31); lwz 9,0x0(31); cmpw 9,0; beq 1f; mr 11,0; 0:; lwz 0,0x0(9); cmpw 0,4; beq 13f; addi 9,9,4; cmpw 9,11; bne 0b; 1:; lwz 9,0x4(31); addi 27,1,8; lwz 0,0xc(31); mr 30,9; cmpw 9,0; beq 2f; lwz 0,0x8(1); stw 0,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 13f; 2:; lwz 9,0x0(31); li 0,1; stw 0,0x10(1); addi 11,1,12; subf 9,9,30; addi 0,1,16; srawi 9,9,2; stw 9,0xc(1); cmplwi 9,1; bge 3f; mr 11,0; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 4f; mr 3,28; bl _s80048590_0; mr 29,3; b 6f; 4:; mr 3,28; bl _s80048590_1; mr 29,3; b 6f; 5:; li 29,0; li 28,0; 6:; lwz 4,0x0(31); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80048590_2; add 3,3,30; b 8f; 7:; mr 3,29; 8:; lwz 0,0x10(1); mr 30,3; mtspr 9,0; cmpwi 0,0; beq 10f; 9:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 9b; 10:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 12f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 11f; bl _s80048590_3; b 12f; 11:; bl _s80048590_4; 12:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 13:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s80048590_0();
extern "C" void _s80048590_1();
extern "C" void _s80048590_2();
extern "C" void _s80048590_3();
extern "C" void _s80048590_4();
extern "C" void f_80048590() {}
