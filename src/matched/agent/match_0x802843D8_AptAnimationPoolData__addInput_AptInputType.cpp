// 0x802843D8 AptAnimationPoolData::addInput(AptInputType, (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); rlwinm 5,5,10,15,21; rlwinm 4,4,17,0,14; ori 5,5,1; rlwinm 6,6,2,22,29; or 4,4,5; or 4,4,6; bl _s802843D8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802843D8_0();
extern "C" void f_802843D8() {}
