// 0x8034D5DC GetDB(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); subfic 3,3,127; xoris 3,3,32768; lis 0,17200; stw 3,0xc(1); lis 9,-32702; lfd f13,0x20d0(9); lis 10,-32702; stw 0,0x8(1); lis 9,-32702; lfs f11,0x20d8(10); lis 8,-32702; lfd f0,0x8(1); lfs f12,0x20dc(9); fsub f0,f0,f13; frsp f0,f0; lfs f13,0x20e0(8); fdivs f0,f0,f11; fsubs f1,f12,f0; fcmpu 0,f1,f13; bge 0f; fmr f1,f13; 0:; bl _s8034D5DC_0; lis 9,-32702; lfs f0,0x20e4(9); fmuls f1,f1,f0; fctiwz f13,f1; stfd f13,0x8(1); lwz 3,0xc(1); cmpwi 3,-904; ble 1f; srawi 3,3,2; 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8034D5DC_0();
extern "C" void f_8034D5DC() {}
