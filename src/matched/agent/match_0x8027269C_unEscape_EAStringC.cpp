// 0x8027269C _unEscape(EAStringC (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lis 11,-32700; lis 10,-32704; lhz 9,-6476(11); addi 0,11,-6476; lhz 8,0x1bb0(10); mr 30,3; addi 9,9,1; stw 0,0x8(1); sth 9,-6476(11); addi 3,1,8; sth 8,0x10(1); lwz 9,0x0(30); lhz 4,0x2(9); bl _s8027269C_0; lwz 9,0x0(30); lbz 11,0x8(9); addi 31,9,9; cmpwi 11,0; beq 4f; 0:; cmpwi 11,43; bne 1f; lbz 0,0x11(1); ori 0,0,8192; b 3f; 1:; cmpwi 11,37; bne 2f; lbz 0,0x0(31); extsb 3,0; cmpwi 3,0; beq 2f; lbz 4,0x1(31); addi 31,31,2; extsb 4,4; bl _s8027269C_1; lbz 0,0x11(1); rlwinm 3,3,0,24,31; rlwinm 3,3,8,0,23; or 0,0,3; b 3f; 2:; lbz 0,0x11(1); rlwinm 9,11,8,0,23; or 0,0,9; 3:; sth 0,0x10(1); addi 3,1,8; addi 4,1,16; bl _s8027269C_2; lbz 11,0x0(31); addi 31,31,1; cmpwi 11,0; bne 0b; 4:; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027269C_3; 5:; lwz 4,0x8(1); stw 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027269C_4; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s8027269C_0();
extern "C" void _s8027269C_1();
extern "C" void _s8027269C_2();
extern "C" void _s8027269C_3();
extern "C" void _s8027269C_4();
extern "C" void f_8027269C() {}
