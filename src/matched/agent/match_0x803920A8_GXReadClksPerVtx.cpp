// 0x803920A8 GXReadClksPerVtx (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s803920A8_0; lwz 3,-21996(13); li 0,4103; sth 0,0x62(3); lwz 3,-21996(13); sth 0,0x60(3); lwz 3,-21996(13); lhz 0,0x64(3); rlwinm 3,0,24,8,31; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s803920A8_0();
extern "C" void f_803920A8() {}
