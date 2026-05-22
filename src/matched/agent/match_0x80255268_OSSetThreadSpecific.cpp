// 0x80255268 OSSetThreadSpecific (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 5,-32768; lwz 5,0xe4(5); cmpwi 5,0; beqlr; cmplwi 3,0; bltlr; cmplwi 3,2; bgelr; rlwinm 0,3,2,0,29; add 3,5,0; stw 4,0x310(3)"
extern "C" void f_80255268() {}
