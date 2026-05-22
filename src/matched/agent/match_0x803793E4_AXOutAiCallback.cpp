// 0x803793E4 __AXOutAiCallback (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 0,-22192(13); cmplwi 0,0; bne 0f; bl _s803793E4_0; stw 4,-22180(13); stw 3,-22184(13); 0:; lwz 0,-22192(13); cmplwi 0,1; bne 1f; li 0,0; stw 0,-22192(13); li 3,0; bl _s803793E4_1; b 2f; 1:; li 0,2; lis 3,-32690; stw 0,-22192(13); addi 3,3,29024; bl _s803793E4_2; 2:; lwz 0,-22152(13); cmplwi 0,1; bne 3f; lwz 4,-22196(13); lis 3,-32690; addi 0,3,10080; mulli 3,4,640; add 3,0,3; li 4,640; bl _s803793E4_3; lwz 4,-22196(13); lis 3,-21845; addi 0,3,-21845; addi 3,4,1; stw 3,-22196(13); lwz 3,-22196(13); mulhwu 0,0,3; rlwinm 0,0,31,1,31; mulli 0,0,3; subf 0,0,3; stw 0,-22196(13); 3:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s803793E4_0();
extern "C" void _s803793E4_1();
extern "C" void _s803793E4_2();
extern "C" void _s803793E4_3();
extern "C" void f_803793E4() {}
