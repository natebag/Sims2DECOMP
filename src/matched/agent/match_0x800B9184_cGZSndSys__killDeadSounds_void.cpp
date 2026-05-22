// 0x800B9184 cGZSndSys::killDeadSounds(void) (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 26,0x30(1); stw 0,0x4c(1); lwz 11,0x404(3); li 0,0; addi 9,1,8; stw 0,0x8(1); stw 11,0x20(1); mr 28,9; stw 0,0x4(9); addi 9,9,8; lwz 11,0x20(1); stw 0,0x4(9); cmpwi 11,0; beq 13f; mr 26,28; 0:; lwz 11,0x20(1); lwz 0,0x4(11); cmpwi 0,0; bne 12f; lwz 9,0x4(26); addi 27,1,32; lwz 0,0xc(26); cmpw 9,0; beq 1f; stw 11,0x0(9); lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 12f; 1:; lwz 30,0x4(28); li 9,1; lwz 0,0x8(1); addi 11,1,40; stw 9,0x28(1); addi 10,1,36; subf 0,0,30; srawi 9,0,2; stw 9,0x24(1); cmplwi 9,1; bge 2f; mr 10,11; 2:; lwz 0,0x0(10); add. 0,9,0; beq 4f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 3f; mr 3,29; bl _s800B9184_0; mr 31,3; b 5f; 3:; mr 3,29; bl _s800B9184_1; mr 31,3; b 5f; 4:; li 31,0; li 29,0; 5:; lwz 4,0x0(28); cmpw 30,4; beq 6f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800B9184_2; add 0,3,30; b 7f; 6:; mr 0,31; 7:; lwz 9,0x28(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 9f; 8:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 8b; 9:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 11f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 10f; bl _s800B9184_3; b 11f; 10:; bl _s800B9184_4; 11:; add 0,29,31; stw 31,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 12:; lwz 9,0x20(1); lwz 0,0x3c(9); cmpwi 0,0; stw 0,0x20(1); bne 0b; 13:; lwz 31,0x4(28); lwz 9,0x8(1); subf 0,9,31; rlwinm. 11,0,30,2,31; beq 16f; mr 30,9; cmpw 30,31; beq 16f; 14:; lwz 11,0x0(30); cmpwi 11,0; beq 15f; lwz 9,0x0(11); li 4,3; lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; 15:; addi 30,30,4; cmpw 30,31; bne 14b; 16:; lwz 3,0x8(1); cmpwi 3,0; beq 18f; lwz 0,0xc(28); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 17f; bl _s800B9184_5; b 18f; 17:; bl _s800B9184_6; 18:; lwz 0,0x4c(1); mtspr 8,0; lmw 26,0x30(1); addi 1,1,72"
extern "C" void _s800B9184_0();
extern "C" void _s800B9184_1();
extern "C" void _s800B9184_2();
extern "C" void _s800B9184_3();
extern "C" void _s800B9184_4();
extern "C" void _s800B9184_5();
extern "C" void _s800B9184_6();
extern "C" void f_800B9184() {}
