// 0x802F678C ERC::NewEntry(int) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 9,0x4(31); cmpw 9,29; ble 0f; lwz 30,0x8(31); rlwinm 0,29,3,0,28; subf 9,29,9; b 2f; 0:; mr 3,31; li 4,4096; li 5,32; bl _s802F678C_0; mr. 3,3; bne 1f; stw 3,0x8(31); li 3,0; b 3f; 1:; lwz 9,0x20(31); mr 30,3; lwz 3,0x8(31); mr 4,30; addi 9,9,1; stw 9,0x20(31); bl _s802F678C_1; rlwinm 0,29,3,0,28; subfic 9,29,512; 2:; add 0,30,0; stw 9,0x4(31); stw 0,0x8(31); mr 3,30; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F678C_0();
extern "C" void _s802F678C_1();
extern "C" void f_802F678C() {}
