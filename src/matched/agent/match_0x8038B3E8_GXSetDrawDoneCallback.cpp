// 0x8038B3E8 GXSetDrawDoneCallback (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; lwz 31,-21924(13); bl _s8038B3E8_0; stw 30,-21924(13); bl _s8038B3E8_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8038B3E8_0();
extern "C" void _s8038B3E8_1();
extern "C" void f_8038B3E8() {}
