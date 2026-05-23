// 0x8024DD28 OSSwitchFPUContext (132B) — Dolphin SDK OSContext.o
// ASMPROC_inject_before: before="blr" replace="rfi" lines="mfmsr 5; ori 5,5,8192; mtmsr 5; isync; lwz 5,0x19c(4); ori 5,5,8192; mtsrr1 5; lis 3,-32768; lwz 5,0xd8(3); stw 4,0xd8(3); cmpw 5,4; beq 1f; cmpwi 5,0; beq 0f; bl _s8024DD28_0; 0:; bl _s8024DD28_1; 1:; lwz 3,0x80(4); mtcr 3; lwz 3,0x84(4); mtlr 3; lwz 3,0x198(4); mtsrr0 3; lwz 3,0x88(4); mtctr 3; lwz 3,0x8c(4); mtxer 3; lhz 3,0x1a2(4); rlwinm 3,3,0,31,29; sth 3,0x1a2(4); lwz 5,0x14(4); lwz 3,0xc(4); lwz 4,0x10(4)"
extern "C" void _s8024DD28_0();
extern "C" void _s8024DD28_1();
extern "C" void OSSwitchFPUContext() {}
