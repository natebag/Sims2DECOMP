// 0x80134E14 RelMatrixImpl::CreateNewArray(int) (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 29,3; mr 30,4; li 3,20; addi 31,29,4; bl _s80134E14_0; li 0,0; addi 9,3,8; stw 0,0x0(3); addi 27,1,16; stw 0,0x4(3); stw 0,0x4(9); stw 30,0x10(3); stw 3,0x10(1); lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 0f; stw 3,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 11f; 0:; lwz 0,0x4(29); li 9,1; stw 9,0x18(1); addi 11,1,24; subf 0,0,30; addi 9,1,20; srawi 3,0,2; stw 3,0x14(1); cmplwi 3,1; bge 1f; mr 9,11; 1:; lwz 0,0x0(9); add. 0,3,0; beq 3f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 2f; mr 3,28; bl _s80134E14_1; mr 29,3; b 4f; 2:; mr 3,28; bl _s80134E14_2; mr 29,3; b 4f; 3:; li 29,0; li 28,0; 4:; lwz 4,0x0(31); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80134E14_3; add 0,3,30; b 6f; 5:; mr 0,29; 6:; lwz 9,0x18(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s80134E14_4; b 10f; 9:; bl _s80134E14_5; 10:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 11:; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s80134E14_0();
extern "C" void _s80134E14_1();
extern "C" void _s80134E14_2();
extern "C" void _s80134E14_3();
extern "C" void _s80134E14_4();
extern "C" void _s80134E14_5();
extern "C" void f_80134E14() {}
