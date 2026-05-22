// 0x80136DB4 RoomManager::ResolveDiagonal(CTilePt (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 23,0x34(1); stw 0,0x5c(1); li 0,0; mr 27,3; stw 0,0x8(1); addi 28,27,16; mr 29,4; mr 26,5; lwz 30,0x4(28); mr 24,6; mr 25,7; mr 23,8; lwz 31,0x4(30); 0:; cmpwi 31,0; beq 2f; addi 3,31,16; mr 4,29; bl _s80136DB4_0; cmpwi 3,0; bne 1f; mr 30,31; lwz 31,0x8(30); b 0b; 1:; lwz 31,0xc(31); b 0b; 2:; lwz 0,0x4(28); cmpw 30,0; beq 3f; mr 3,29; addi 4,30,16; bl _s80136DB4_1; cmpwi 3,0; beq 4f; 3:; lwz 30,0x4(28); 4:; lwz 0,0x14(27); stw 30,0x10(1); cmpw 30,0; stw 30,0x8(1); stw 0,0x10(1); beq 5f; addi 4,30,16; addi 3,1,24; bl _s80136DB4_2; lwz 11,0x14(30); lwz 12,0x18(30); addi 3,1,24; li 4,2; stw 11,0x1c(1); stw 12,0x20(1); lwz 9,0x1c(30); lwz 10,0x20(30); lhz 0,0x1c(1); stw 9,0x24(1); stw 10,0x28(1); lwz 11,0x20(1); sth 0,0x0(26); lhz 9,0x24(1); stw 11,0x0(25); lwz 0,0x28(1); sth 9,0x0(24); stw 0,0x0(23); bl _s80136DB4_3; li 3,1; b 6f; 5:; li 0,0; li 9,0; sth 0,0x0(26); li 3,0; sth 0,0x0(24); stw 9,0x0(25); stw 9,0x0(23); 6:; lwz 0,0x5c(1); mtspr 8,0; lmw 23,0x34(1); addi 1,1,88"
extern "C" void _s80136DB4_0();
extern "C" void _s80136DB4_1();
extern "C" void _s80136DB4_2();
extern "C" void _s80136DB4_3();
extern "C" void f_80136DB4() {}
