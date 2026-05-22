// 0x80185068 ActionQueueHUD::AddAction(ActionQueueHUD::ActionQueueItem (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 0,0x28(5); mr 31,3; mr 29,4; mr 28,6; cmpwi 0,49; li 27,1; ble 0f; li 27,5; 0:; lbz 0,0x308(31); cmplwi 0,17; ble 1f; mr 3,31; bl _s80185068_0; lbz 0,0x308(31); cmplwi 0,17; bgt 2f; 1:; lbz 30,0x308(31); mr 4,29; mulli 30,30,20; add 30,30,31; addi 30,30,344; mr 3,30; bl _s80185068_1; lbz 9,0x10(29); addi 11,31,704; stb 9,0x10(30); lbz 0,0x11(29); stb 0,0x11(30); lbz 9,0x308(31); mulli 9,9,20; add 9,31,9; stb 27,0x168(9); lbz 0,0x308(31); rlwinm 0,0,2,0,29; stwx 28,11,0; lbz 9,0x308(31); lbz 0,0x30a(31); addi 9,9,1; stb 9,0x308(31); cmpwi 0,0; bne 2f; mr 3,31; bl _s80185068_2; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80185068_0();
extern "C" void _s80185068_1();
extern "C" void _s80185068_2();
extern "C" void f_80185068() {}
