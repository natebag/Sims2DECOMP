// 0x80350240 ENgcTextureBase::UpdateEnd(void) (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x98(31); cmpwi 0,3; beq 8f; lwz 0,0x8(31); andi. 0,0,1; beq 0f; li 0,1; 0:; stw 0,0x68(31); lwz 0,0x8(31); andi. 0,0,2; beq 1f; li 0,1; 1:; stw 0,0x6c(31); lwz 0,0x8(31); addi 29,1,16; addi 28,1,20; andi. 9,0,128; bne 6f; lwz 0,0x98(31); cmpwi 0,1; beq 5f; li 30,0; b 3f; 2:; mr 4,30; addi 5,1,8; addi 6,1,12; mr 3,31; bl _s80350240_0; addi 30,30,1; lwz 9,0x24(31); lwz 4,0x78(31); lha 3,0xa8(9); lwz 0,0xac(9); add 3,31,3; lwz 5,0x8(1); lwz 6,0xc(1); mtspr 8,0; lwz 7,0x74(31); blrl; 3:; lhz 0,0x16(31); cmplwi 0,1; ble 4f; cmpw 30,0; blt 2b; b 5f; 4:; cmpwi 30,0; ble 2b; 5:; lwz 0,0x8(31); andi. 30,0,2048; bne 6f; lwz 0,0x78(31); cmpwi 0,0; beq 6f; bl _s80350240_1; lwz 4,0x78(31); bl _s80350240_2; stw 30,0x78(31); 6:; lhz 0,0x16(31); li 4,1; cmplwi 0,1; ble 7f; mr 4,0; 7:; mr 5,29; mr 6,28; mr 3,31; bl _s80350240_3; mr 4,3; lwz 3,0x74(31); bl _s80350240_4; 8:; lwz 3,0x90(31); cmpwi 3,0; beq 9f; lhz 9,0x14(31); lbz 0,0x1b(31); mullw 9,9,0; addi 4,9,7; rlwinm 4,4,29,3,31; bl _s80350240_5; 9:; addi 3,31,40; bl _s80350240_6; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80350240_0();
extern "C" void _s80350240_1();
extern "C" void _s80350240_2();
extern "C" void _s80350240_3();
extern "C" void _s80350240_4();
extern "C" void _s80350240_5();
extern "C" void _s80350240_6();
extern "C" void f_80350240() {}
