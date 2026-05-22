// 0x802593F0 SIUnregisterPollingHandler (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s802593F0_0; lis 4,-32694; li 0,4; addi 5,4,-21456; mtspr 9,0; addi 31,3,0; addi 3,5,0; li 4,0; 0:; lwz 0,0x0(3); cmplw 0,30; bne 3f; lis 3,-32694; rlwinm 4,4,2,0,29; addi 0,3,-21456; add 3,0,4; li 0,0; stw 0,0x0(3); li 4,0; lwz 0,0x0(5); cmplwi 0,0; bne 1f; addi 3,5,4; lwz 0,0x4(5); li 4,1; cmplwi 0,0; bne 1f; lwzu 0,0x4(3); li 4,2; cmplwi 0,0; bne 1f; lwz 0,0x4(3); li 4,3; cmplwi 0,0; bne 1f; li 4,4; 1:; cmpwi 4,4; bne 2f; li 3,0; bl _s802593F0_1; 2:; mr 3,31; bl _s802593F0_2; li 3,1; b 4f; 3:; addi 3,3,4; addi 4,4,1; bdnz 0b; mr 3,31; bl _s802593F0_3; li 3,0; 4:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802593F0_0();
extern "C" void _s802593F0_1();
extern "C" void _s802593F0_2();
extern "C" void _s802593F0_3();
extern "C" void f_802593F0() {}
