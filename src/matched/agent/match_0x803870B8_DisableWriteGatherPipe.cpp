// 0x803870B8 DisableWriteGatherPipe (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s803870B8_0; rlwinm 3,3,0,2,0; bl _s803870B8_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s803870B8_0();
extern "C" void _s803870B8_1();
extern "C" void f_803870B8() {}
