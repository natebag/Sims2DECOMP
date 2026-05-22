// 0x803782D0 __AXPushStackHead (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 5,-32690; rlwinm 7,4,2,0,29; addi 0,5,-3232; add 6,0,7; lwz 5,0x0(6); li 0,0; stw 5,0x0(3); stw 0,0x4(3); lwz 0,0x0(3); cmplwi 0,0; beq 0f; lwz 5,0x0(6); stw 3,0x4(5); stw 3,0x0(6); b 1f; 0:; lis 5,-32690; addi 0,5,-3104; add 5,0,7; stw 3,0x0(5); stw 3,0x0(6); 1:; stw 4,0xc(3)"
extern "C" void f_803782D0() {}
