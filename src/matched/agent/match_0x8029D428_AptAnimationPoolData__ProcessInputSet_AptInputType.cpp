// 0x8029D428 AptAnimationPoolData::ProcessInputSet(AptInputType, (640 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 20,0x10(1); stw 0,0x44(1); stw 12,0xc(1); mr 31,3; li 28,0; addi 9,31,32; mr 22,4; lhz 0,0x2(9); mr 25,5; mr 29,6; li 23,0; cmpw 28,0; li 24,0; bge 8f; cmpwi 25,0; lhz 0,0x20(31); mfcr 20; cmpw 28,0; beq 8f; rlwinm 0,29,15,17,31; rlwinm 27,29,0,30,31; cmpwi 2,0,502; mr 21,9; cmpwi 3,27,1; li 26,0; cmpwi 4,25,1; 0:; lwz 9,0x24(31); lwzx 30,26,9; cmpwi 30,0; beq 7f; lwz 3,-23008(13); mr 4,30; bl _s8029D428_0; cmpwi 3,0; bne 7f; mtcrf 128,20; beq 1f; beq cr4,5f; b 6f; 1:; cmpwi 7,27,1; rlwinm 0,29,15,17,31; bne cr7,2f; beq cr2,3f; 2:; cmpwi 0,501; bne 4f; 3:; mr 3,30; li 4,64; mr 5,29; li 6,0; bl _s8029D428_1; b 6f; 4:; bne cr7,6f; mr 3,30; li 4,64; mr 5,29; li 6,0; bl _s8029D428_2; cmpwi 23,0; bne 6f; mr 3,30; lis 4,2; mr 5,29; li 6,1; bl _s8029D428_3; mr 23,3; b 6f; 5:; bne cr3,6f; mr 3,30; li 4,128; mr 5,29; li 6,0; bl _s8029D428_4; 6:; addi 28,28,1; 7:; lhz 0,0x2(21); addi 24,24,1; addi 26,26,4; cmpw 24,0; bge 8f; lhz 0,0x20(31); cmpw 28,0; bne 0b; 8:; cmpwi 25,0; bne 14f; lhz 11,0x8(31); cmpwi 11,0; beq 14f; cmpwi 23,0; bne 14f; addi 9,31,8; li 28,0; lhz 0,0x2(9); mr 25,9; li 26,0; cmpw 28,0; bge 14f; cmpw 28,11; beq 14f; li 27,0; 9:; lwz 9,0xc(31); lwzx 29,27,9; cmpwi 29,0; beq 13f; lwz 3,-23008(13); mr 4,29; bl _s8029D428_5; cmpwi 3,0; bne 13f; lwz 9,0x4c(29); li 7,0; lwz 8,0x8(9); mr 6,9; lwz 0,0x34(8); cmpw 7,0; bge 12f; li 10,0; 10:; lwz 9,0x8(6); lwz 11,0x38(9); lwzx 0,10,11; andi. 9,0,65024; beq 11f; lwz 9,0x38(8); lwzx 0,10,9; add 30,10,9; rlwinm 0,0,23,25,31; cmpw 22,0; bne 11f; lwz 28,0x48(29); addi 30,30,4; lwz 29,-27612(13); mr 3,31; bl _s8029D428_6; mr 4,30; mr 5,28; mr 6,29; bl _s8029D428_7; b 14f; 11:; lwz 0,0x34(8); addi 7,7,1; addi 10,10,8; cmpw 7,0; blt 10b; 12:; addi 28,28,1; 13:; lhz 0,0x2(25); addi 26,26,1; addi 27,27,4; cmpw 26,0; bge 14f; lhz 0,0x8(31); cmpw 28,0; bne 9b; 14:; lwz 0,0x44(1); lwz 12,0xc(1); mtspr 8,0; lmw 20,0x10(1); mtcrf 56,12; addi 1,1,64"
extern "C" void _s8029D428_0();
extern "C" void _s8029D428_1();
extern "C" void _s8029D428_2();
extern "C" void _s8029D428_3();
extern "C" void _s8029D428_4();
extern "C" void _s8029D428_5();
extern "C" void _s8029D428_6();
extern "C" void _s8029D428_7();
extern "C" void f_8029D428() {}
