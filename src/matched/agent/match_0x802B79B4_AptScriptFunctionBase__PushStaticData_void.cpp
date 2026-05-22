// 0x802B79B4 AptScriptFunctionBase::PushStaticData(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26968(13); li 9,0; lwz 3,-26972(13); rlwinm 0,0,2,0,29; stw 9,-26968(13); add 0,3,0; stw 0,-26972(13)"
extern "C" void f_802B79B4() {}
