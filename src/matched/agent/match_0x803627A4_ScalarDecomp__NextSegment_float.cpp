// 0x803627A4 ScalarDecomp::NextSegment(float) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); mr 31,3; fmr f31,f1; lwz 9,0x8(31); lha 0,0x1c(31); addi 9,9,1; lwz 11,0x10(31); addi 4,9,1; lwz 10,0x4(31); mullw 4,4,0; lbz 5,0x1e(31); lwz 3,0x0(31); stw 11,0xc(31); extsb 5,5; stw 9,0x8(31); add 4,10,4; bl _s803627A4_0; lwz 11,0x10(31); lwz 0,0xc(31); lis 8,17200; addi 11,11,1; lfs f0,0x28(31); add 11,11,3; lis 9,-32702; subf 0,0,11; fsubs f31,f31,f0; xoris 0,0,32768; lfd f13,0x2ef0(9); stw 0,0xc(1); lis 9,-32702; lfs f12,0x2ef8(9); stw 8,0x8(1); lwz 5,0x8(31); lfd f0,0x8(1); addi 30,5,1; stw 11,0x10(31); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; fcmpu 7,f31,f0; cror 31,30,29; mfcr 0; rlwinm 0,0,0,31,31; cmpwi 0,0; stb 0,0x21(31); bne 0f; mr 3,31; li 4,1; addi 6,31,48; bl _s803627A4_1; mr 3,31; li 4,0; mr 5,30; addi 6,31,52; bl _s803627A4_2; 0:; lfs f0,0x38(31); mr 3,31; mr 5,30; li 4,2; stfs f0,0x2c(31); addi 6,3,56; bl _s803627A4_3; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s803627A4_0();
extern "C" void _s803627A4_1();
extern "C" void _s803627A4_2();
extern "C" void _s803627A4_3();
extern "C" void f_803627A4() {}
