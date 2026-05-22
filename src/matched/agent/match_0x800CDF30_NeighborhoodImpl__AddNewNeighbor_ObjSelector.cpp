// 0x800CDF30 NeighborhoodImpl::AddNewNeighbor(ObjSelector (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 27,3; mr. 25,4; bne 0f; li 3,0; b 17f; 0:; addi 9,27,116; lwz 11,0x74(27); lwz 0,0x4(9); mr 29,9; li 31,0; cmpw 11,0; beq 3f; mr 8,0; li 10,0; 1:; lwz 0,0x0(11); cmpwi 0,0; bne 2f; srawi 9,10,2; addi 31,9,1; 2:; addi 11,11,4; addi 10,10,4; cmpw 11,8; bne 1b; 3:; cmpwi 31,0; bne 16f; lwz 30,0x4(29); addi 26,1,8; lwz 0,0xc(29); stw 31,0x8(1); cmpw 30,0; beq 4f; stw 31,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 15f; 4:; lwz 0,0x74(27); li 9,1; stw 9,0x10(1); addi 10,1,16; subf 0,0,30; addi 11,1,12; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 5f; mr 11,10; 5:; lwz 0,0x0(11); add. 0,9,0; beq 7f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 6f; mr 3,28; bl _s800CDF30_0; mr 31,3; b 8f; 6:; mr 3,28; bl _s800CDF30_1; mr 31,3; b 8f; 7:; li 31,0; li 28,0; 8:; lwz 4,0x0(29); cmpw 30,4; beq 9f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800CDF30_2; add 0,3,30; b 10f; 9:; mr 0,31; 10:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 12f; 11:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 11b; 12:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 14f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 13f; bl _s800CDF30_3; b 14f; 13:; bl _s800CDF30_4; 14:; add 0,28,31; stw 31,0x0(29); stw 30,0x4(29); stw 0,0xc(29); 15:; lwz 0,0x4(29); lwz 9,0x74(27); subf 0,9,0; srawi 31,0,2; 16:; bl _s800CDF30_5; li 6,0; li 4,440; li 5,1; bl _s800CDF30_6; mr 5,25; extsh 4,31; bl _s800CDF30_7; addi 9,31,-1; lwz 11,0x74(27); rlwinm 9,9,2,0,29; stwx 3,11,9; 17:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s800CDF30_0();
extern "C" void _s800CDF30_1();
extern "C" void _s800CDF30_2();
extern "C" void _s800CDF30_3();
extern "C" void _s800CDF30_4();
extern "C" void _s800CDF30_5();
extern "C" void _s800CDF30_6();
extern "C" void _s800CDF30_7();
extern "C" void f_800CDF30() {}
