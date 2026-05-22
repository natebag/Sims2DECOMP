// 0x803904E0 GXEndDisplayList (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32688; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,3,-21840; stw 30,0x10(1); stw 29,0xc(1); stw 28,0x8(1); bl _s803904E0_0; lwz 4,-22000(13); mr 3,31; lwz 0,0x14(4); rlwinm 30,0,6,31,31; bl _s803904E0_1; lwz 3,-21904(13); bl _s803904E0_2; lwz 3,-17720(13); lbz 0,0x5a9(3); cmplwi 0,0; beq 0f; bl _s803904E0_3; lwz 4,-17720(13); mr 29,3; li 5,1456; lwz 28,0x8(4); addi 3,4,0; addi 4,31,36; bl _s803904E0_4; lwz 4,-17720(13); mr 3,29; stw 28,0x8(4); bl _s803904E0_5; 0:; lwz 3,-17720(13); li 0,0; cmplwi 30,0; stb 0,0x5a8(3); bne 1f; lwz 3,0x1c(31); b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); lwz 29,0xc(1); lwz 28,0x8(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803904E0_0();
extern "C" void _s803904E0_1();
extern "C" void _s803904E0_2();
extern "C" void _s803904E0_3();
extern "C" void _s803904E0_4();
extern "C" void _s803904E0_5();
extern "C" void f_803904E0() {}
