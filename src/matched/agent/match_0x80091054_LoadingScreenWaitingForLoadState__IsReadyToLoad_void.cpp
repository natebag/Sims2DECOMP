// 0x80091054 LoadingScreenWaitingForLoadState::IsReadyToLoad(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 3,0x8(3); bl _s80091054_0; lis 0,17200; stw 3,0xc(1); lis 9,-32706; lfd f0,-32552(9); stw 0,0x8(1); lfd f1,0x8(1); fsub f1,f1,f0; frsp f1,f1; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80091054_0();
extern "C" void f_80091054() {}
