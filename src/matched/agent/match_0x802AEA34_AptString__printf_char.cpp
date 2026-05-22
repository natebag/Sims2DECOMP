// 0x802AEA34 AptString::printf(char (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 30,0x98(1); stw 0,0xa4(1); lis 12,512; addi 0,1,168; addi 11,1,8; stw 0,0x84(1); stw 11,0x88(1); mr 31,3; stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); stw 12,0x80(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; addi 11,1,128; addi 9,1,112; lwz 0,0x4(11); lis 30,-32694; lwz 10,0x8(11); mr 5,9; stw 12,0x70(1); addi 3,30,-13436; stw 0,0x4(9); stw 10,0x8(9); bl _s802AEA34_0; addi 4,30,-13436; addi 3,1,144; bl _s802AEA34_1; lwz 11,0x90(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AEA34_2; 1:; lwz 4,0x90(1); stw 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AEA34_3; 2:; lwz 0,0xa4(1); mtspr 8,0; lmw 30,0x98(1); addi 1,1,160"
extern "C" void _s802AEA34_0();
extern "C" void _s802AEA34_1();
extern "C" void _s802AEA34_2();
extern "C" void _s802AEA34_3();
extern "C" void f_802AEA34() {}
