// 0x803794B4 __AXDSPResumeCallback (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 0,-22192(13); cmplwi 0,2; bne 0f; li 0,0; stw 0,-22192(13); bl _s803794B4_0; lwz 5,-22184(13); lwz 0,-22180(13); subfc 0,0,4; rlwinm 0,0,30,2,31; mr 3,0; bl _s803794B4_1; b 1f; 0:; li 0,1; stw 0,-22192(13); 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s803794B4_0();
extern "C" void _s803794B4_1();
extern "C" void f_803794B4() {}
