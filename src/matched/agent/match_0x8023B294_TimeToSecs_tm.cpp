// 0x8023B294 _TimeToSecs(tm (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 28,0x30(1); stw 0,0x44(1); mr 31,3; li 28,0; li 29,-1; 0:; add 0,28,29; addi 3,1,8; rlwinm 30,0,31,1,31; mr 4,30; bl _s8023B294_0; lwz 9,0x1c(1); lwz 0,0x14(31); subf. 9,0,9; bne 1f; lwz 9,0x18(1); lwz 0,0x10(31); subf. 9,0,9; bne 1f; lwz 9,0x14(1); lwz 0,0xc(31); subf. 9,0,9; bne 1f; lwz 9,0x10(1); lwz 0,0x8(31); subf. 9,0,9; bne 1f; lwz 9,0xc(1); lwz 0,0x4(31); subf. 9,0,9; bne 1f; lwz 9,0x8(1); lwz 0,0x0(31); subf. 9,0,9; beq 4f; 1:; cmpwi 9,0; ble 2f; addi 29,30,-1; b 3f; 2:; addi 28,30,1; 3:; cmplw 28,29; ble 0b; 4:; cmpwi 9,0; li 3,0; bne 5f; mr 3,30; 5:; lwz 0,0x44(1); mtspr 8,0; lmw 28,0x30(1); addi 1,1,64"
extern "C" void _s8023B294_0();
extern "C" void f_8023B294() {}
