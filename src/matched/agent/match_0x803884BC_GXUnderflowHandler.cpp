// 0x803884BC GXUnderflowHandler (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 3,-21952(13); bl _s803884BC_0; li 0,0; stw 0,-21944(13); li 3,1; li 4,1; bl _s803884BC_1; li 3,1; li 4,0; bl _s803884BC_2; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s803884BC_0();
extern "C" void _s803884BC_1();
extern "C" void _s803884BC_2();
extern "C" void f_803884BC() {}
