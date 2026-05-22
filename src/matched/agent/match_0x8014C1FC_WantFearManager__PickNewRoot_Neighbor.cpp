// 0x8014C1FC WantFearManager::PickNewRoot(Neighbor (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 23,0x1c(1); stw 0,0x44(1); mr 30,4; mr 27,3; lwz 9,0x4(30); mr 26,5; mr 24,6; addi 25,1,8; lwz 3,0x8(9); li 28,0; rlwinm 3,3,2,0,29; bl _s8014C1FC_0; lwz 9,0x4(30); mr 29,3; lwz 0,0x8(9); cmplw 28,0; bge 2f; li 23,0; li 31,0; 0:; lwz 9,0xc(30); li 4,0; lwzx 3,31,9; bl _s8014C1FC_1; bl _s8014C1FC_2; stwx 23,31,29; lwz 9,0xc(30); lwzx 9,31,9; lhz 0,0x2(9); andi. 11,0,1; bne 1f; lbz 0,0x2(3); xori 0,0,128; subfic 11,0,0; adde 0,11,0; cmpw 24,0; bne 1f; lwz 4,0x28(9); mr 3,26; li 5,0; addi 4,4,16; bl _s8014C1FC_3; stwx 3,31,29; 1:; lwz 9,0x4(30); addi 28,28,1; addi 31,31,4; lwz 0,0x8(9); cmplw 28,0; blt 0b; 2:; addi 3,1,8; bl _s8014C1FC_4; mr 28,25; li 24,0; 3:; lwz 9,0x4(30); mr 3,30; mr 4,29; lwz 5,0x8(9); bl _s8014C1FC_5; cmpwi 3,-1; bne 4f; addi 3,1,8; bl _s8014C1FC_6; lwz 0,0x8(28); lwz 9,0x8(1); lwz 11,0x4(28); b 9f; 4:; lwz 11,0xc(30); rlwinm 31,3,2,0,29; li 4,0; lwzx 9,31,11; lhz 0,0x0(9); sth 0,0x8(1); lwzx 3,31,11; bl _s8014C1FC_7; stw 3,0x4(28); mr 4,28; mr 3,26; bl _s8014C1FC_8; cmpwi 3,-1; bne 5f; mr 3,25; mr 4,26; li 5,1; bl _s8014C1FC_9; cmpwi 3,0; bne 6f; 5:; stwx 24,31,29; li 0,0; b 7f; 6:; li 0,1; 7:; cmpwi 0,0; beq 3b; cmpwi 29,0; beq 8f; mr 3,29; bl _s8014C1FC_10; 8:; addi 3,1,8; bl _s8014C1FC_11; lwz 0,0x8(25); lwz 9,0x8(1); lwz 11,0x4(25); 9:; stw 9,0x0(27); stw 11,0x4(27); stw 0,0x8(27); mr 3,27; lwz 0,0x44(1); mtspr 8,0; lmw 23,0x1c(1); addi 1,1,64"
extern "C" void _s8014C1FC_0();
extern "C" void _s8014C1FC_1();
extern "C" void _s8014C1FC_2();
extern "C" void _s8014C1FC_3();
extern "C" void _s8014C1FC_4();
extern "C" void _s8014C1FC_5();
extern "C" void _s8014C1FC_6();
extern "C" void _s8014C1FC_7();
extern "C" void _s8014C1FC_8();
extern "C" void _s8014C1FC_9();
extern "C" void _s8014C1FC_10();
extern "C" void _s8014C1FC_11();
extern "C" void f_8014C1FC() {}
