// 0x8038B770 __GXSetDirtyState (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); lwz 3,-17720(13); lwz 31,0x5ac(3); rlwinm. 0,31,0,31,31; beq 0f; bl _s8038B770_0; 0:; rlwinm. 0,31,0,30,30; beq 1f; bl _s8038B770_1; 1:; rlwinm. 0,31,0,29,29; beq 2f; bl _s8038B770_2; 2:; rlwinm. 0,31,0,28,28; beq 3f; bl _s8038B770_3; 3:; rlwinm. 0,31,0,27,27; beq 4f; bl _s8038B770_4; 4:; rlwinm. 0,31,0,27,28; beq 5f; bl _s8038B770_5; 5:; lwz 3,-17720(13); li 0,0; stw 0,0x5ac(3); lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8038B770_0();
extern "C" void _s8038B770_1();
extern "C" void _s8038B770_2();
extern "C" void _s8038B770_3();
extern "C" void _s8038B770_4();
extern "C" void _s8038B770_5();
extern "C" void f_8038B770() {}
