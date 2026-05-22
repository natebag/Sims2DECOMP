// 0x80336C90 INVTarget::SetInvBldItemCount(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22536(13); li 4,640; rlwinm 3,0,2,0,29; add 3,3,0; rlwinm 3,3,7,0,24; add 3,3,31; bl _s80336C90_0; mr 3,30; bl _s80336C90_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80336C90_0();
extern "C" void _s80336C90_1();
extern "C" int f_80336C90() {}
