// 0x8031682C ERFont::Draw(ERC (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; mfcr 12; stmw 23,0x24(1); stw 0,0x4c(1); stw 12,0x20(1); mr 31,5; mr 28,3; mr 27,4; mr 29,6; mr 25,7; mr 24,8; mr 23,9; mr 26,10; mr 3,31; bl _s8031682C_0; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s8031682C_1; mr. 30,3; mcrf cr4,cr0; beq cr4,6f; mr 3,31; bl _s8031682C_2; mr 5,31; addi 3,3,1; add 0,5,3; addi 6,1,24; mr 10,30; cmplw 5,0; bge 5f; mr 8,0; 0:; lbz 9,0x0(5); andi. 0,9,128; bne 1f; sth 9,0x0(10); addi 5,5,1; b 3f; 1:; rlwinm 0,9,0,24,26; cmpwi 0,192; bne 2f; lbz 0,0x1(5); rlwinm 9,9,6,21,25; addi 5,5,2; rlwinm 0,0,0,26,31; or 0,0,9; sth 0,0x0(10); b 3f; 2:; rlwinm 0,9,0,24,27; cmpwi 0,224; bne 4f; lbz 0,0x1(5); rlwinm 11,9,12,16,19; lbz 9,0x2(5); rlwinm 0,0,6,20,25; addi 5,5,3; or 11,11,0; rlwinm 9,9,0,26,31; or 9,9,11; sth 9,0x0(10); 3:; addi 10,10,2; 4:; cmplw 5,8; blt 0b; 5:; lfs f0,0x0(29); mr 7,6; lfs f13,0x4(29); mr 3,28; stfs f0,0x18(1); mr 4,27; stfs f13,0x4(6); mr 8,25; stw 26,0x8(1); mr 9,24; lwz 0,0x50(1); mr 10,23; mr 5,30; li 6,1; stw 0,0xc(1); lwz 0,0x54(1); stw 0,0x10(1); lwz 0,0x58(1); stw 0,0x14(1); bl _s8031682C_3; beq cr4,6f; mr 3,30; bl _s8031682C_4; 6:; lwz 0,0x4c(1); lwz 12,0x20(1); mtspr 8,0; lmw 23,0x24(1); mtcrf 8,12; addi 1,1,72"
extern "C" void _s8031682C_0();
extern "C" void _s8031682C_1();
extern "C" void _s8031682C_2();
extern "C" void _s8031682C_3();
extern "C" void _s8031682C_4();
extern "C" void f_8031682C() {}
