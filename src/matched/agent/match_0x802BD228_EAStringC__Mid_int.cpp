// 0x802BD228 EAStringC::Mid(int) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; mr. 5,5; bgt 0f; lwz 11,0x0(4); stw 11,0x0(31); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); b 2f; 0:; lwz 11,0x0(4); lhz 0,0x2(11); subf. 4,5,0; bgt 1f; lis 11,-32700; addi 0,11,-6476; stw 0,0x0(31); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); b 2f; 1:; stw 11,0x8(1); mr 6,4; mr 8,4; addi 3,1,8; lhz 9,0x0(11); li 7,1; addi 9,9,1; sth 9,0x0(11); bl _s802BD228_0; lwz 11,0x8(1); stw 11,0x0(31); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BD228_1; 2:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s802BD228_0();
extern "C" void _s802BD228_1();
extern "C" void f_802BD228() {}
