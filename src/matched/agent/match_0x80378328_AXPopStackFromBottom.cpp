// 0x80378328 __AXPopStackFromBottom (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32690; rlwinm 5,3,2,0,29; addi 0,4,-3232; add 7,0,5; lwz 6,0x0(7); li 3,0; cmplwi 6,0; beqlr; lis 4,-32690; addi 0,4,-3104; add 5,0,5; lwz 8,0x0(5); cmplw 6,8; bne 0f; li 0,0; stw 0,0x0(5); mr 3,6; stw 0,0x0(7); blr; 0:; cmplwi 8,0; beqlr; lwz 4,0x4(8); li 0,0; addi 3,8,0; stw 4,0x0(5); lwz 4,0x0(5); stw 0,0x0(4)"
extern "C" void f_80378328() {}
