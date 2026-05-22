// 0x8037B6A8 AXSetVoiceSrcRatio (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stfd f31,0x20(1); fmr f31,f1; stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; bl _s8037B6A8_0; lfs f0,-17776(13); mr 30,3; fmuls f31,f0,f31; fmr f1,f31; bl _s8037B6A8_1; fmr f1,f31; mr 31,3; bl _s8037B6A8_2; lis 0,4; cmplw 3,0; ble 0f; lis 31,4; 0:; rlwinm 0,31,16,16,31; sth 0,0x1de(29); mr 3,30; sth 31,0x1e0(29); lwz 0,0x1c(29); oris 0,0,8; stw 0,0x1c(29); bl _s8037B6A8_3; lwz 0,0x2c(1); lfd f31,0x20(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8037B6A8_0();
extern "C" void _s8037B6A8_1();
extern "C" void _s8037B6A8_2();
extern "C" void _s8037B6A8_3();
extern "C" void f_8037B6A8() {}
