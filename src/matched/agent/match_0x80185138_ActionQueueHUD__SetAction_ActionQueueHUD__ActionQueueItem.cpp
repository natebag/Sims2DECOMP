// 0x80185138 ActionQueueHUD::SetAction(ActionQueueHUD::ActionQueueItem (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lbz 0,0x308(31); mr 28,5; cmplwi 0,17; ble 0f; bl _s80185138_0; lbz 0,0x308(31); cmplwi 0,17; bgt 1f; 0:; lbz 30,0x308(31); mr 4,29; mulli 30,30,20; add 30,30,31; addi 30,30,344; mr 3,30; bl _s80185138_1; lbz 9,0x10(29); li 11,4; addi 10,31,704; stb 9,0x10(30); lbz 0,0x11(29); stb 0,0x11(30); lbz 9,0x308(31); mulli 9,9,20; add 9,31,9; stb 11,0x168(9); lbz 0,0x308(31); lwz 11,0x38(28); rlwinm 0,0,2,0,29; stwx 11,10,0; lbz 9,0x308(31); lbz 0,0x30a(31); addi 9,9,1; stb 9,0x308(31); cmpwi 0,0; bne 1f; mr 3,31; bl _s80185138_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80185138_0();
extern "C" void _s80185138_1();
extern "C" void _s80185138_2();
extern "C" void f_80185138() {}
