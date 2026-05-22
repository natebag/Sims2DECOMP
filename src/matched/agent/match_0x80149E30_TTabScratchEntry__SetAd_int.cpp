// 0x80149E30 TTabScratchEntry::SetAd(int, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); rlwinm 4,4,4,0,27; add 9,4,3; lwz 11,0x8(9); addi 4,4,8; add 3,3,4; lha 0,0x20(11); mr 4,5; lwz 9,0x24(11); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80149E30() {}
