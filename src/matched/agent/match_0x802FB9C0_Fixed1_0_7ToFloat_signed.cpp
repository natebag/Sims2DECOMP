// 0x802FB9C0 Fixed1_0_7ToFloat(signed (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); xoris 3,3,32768; stw 3,0xc(1); lis 0,17200; lis 11,-32702; lis 10,-32702; stw 0,0x8(1); lis 8,-32702; lfd f13,-2768(11); lfd f0,0x8(1); lfs f12,-2760(10); fsub f0,f0,f13; lfs f1,-2756(8); frsp f0,f0; fdivs f0,f0,f12; fcmpu 0,f0,f1; blt 0f; lis 9,-32702; fmr f1,f0; lfs f13,-2752(9); fcmpu 0,f0,f13; ble 0f; fmr f1,f13; 0:; addi 1,1,16"
extern "C" void f_802FB9C0() {}
