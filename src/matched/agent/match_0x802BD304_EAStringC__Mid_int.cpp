// 0x802BD304 EAStringC::Mid(int, (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; mr 11,5; cmpwi 5,0; bge 0f; add 6,6,5; li 11,0; 0:; cmpwi 6,0; ble 1f; lwz 10,0x0(4); lhz 0,0x2(10); subf. 4,11,0; bgt 2f; 1:; lis 11,-32700; addi 0,11,-6476; stw 0,0x0(31); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); b 4f; 2:; cmpw 6,4; bge 3f; mr 4,6; 3:; stw 10,0x8(1); mr 6,4; mr 8,4; addi 3,1,8; lhz 9,0x0(10); li 7,1; addi 9,9,1; sth 9,0x0(10); bl _s802BD304_0; lwz 11,0x8(1); stw 11,0x0(31); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BD304_1; 4:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s802BD304_0();
extern "C" void _s802BD304_1();
extern "C" void f_802BD304() {}
