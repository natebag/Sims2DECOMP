// 0x8037823C __AXRemoveFromStack (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); lis 5,-32690; lis 4,-32690; rlwinm 6,0,2,0,29; addi 5,5,-3232; addi 0,4,-3104; add 7,5,6; add 5,0,6; lwz 4,0x0(7); lwz 0,0x0(5); cmplw 4,0; bne 0f; li 0,0; stw 0,0x0(5); stw 0,0x0(7); blr; 0:; cmplw 3,4; bne 1f; lwz 3,0x0(3); li 0,0; stw 3,0x0(7); lwz 3,0x0(7); stw 0,0x4(3); blr; 1:; cmplw 3,0; bne 2f; lwz 3,0x4(3); li 0,0; stw 3,0x0(5); lwz 3,0x0(5); stw 0,0x0(3); blr; 2:; lwz 4,0x4(3); lwz 3,0x0(3); stw 3,0x0(4); stw 4,0x4(3)"
extern "C" void f_8037823C() {}
