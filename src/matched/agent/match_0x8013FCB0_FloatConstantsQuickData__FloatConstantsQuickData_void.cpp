// 0x8013FCB0 FloatConstantsQuickData::FloatConstantsQuickData(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="ori 4,4,65535; bl _s8013FCB0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; rlwinm 0,4,1,0,30; add 0,0,4; sraw 3,3,0; rlwinm 3,3,0,29,31; blr; rlwinm 9,4,1,0,30; lwz 11,0x0(3); add 9,9,4; li 0,7; slw 0,0,9; slw 5,5,9; andc 0,11,0; or 0,0,5; stw 0,0x0(3)"
extern "C" void _s8013FCB0_0();
extern "C" void f_8013FCB0() {}
