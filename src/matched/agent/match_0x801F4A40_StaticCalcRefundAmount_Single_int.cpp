// 0x801F4A40 StaticCalcRefundAmount_Single(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mr. 3,3; beq 0f; cmpwi 4,0; bne 1f; 0:; li 3,0; b 3f; 1:; xoris 0,3,32768; stw 0,0xc(1); lis 11,17200; lis 10,-32704; lis 8,-32704; stw 11,0x8(1); lfd f13,-23632(10); mr 11,9; lfd f0,0x8(1); lfs f12,-23624(8); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; fmr f13,f0; fctiwz f11,f13; stfd f11,0x8(1); lwz 3,0xc(1); cmpwi 3,0; bgt 2f; li 3,1; 2:; mullw 3,3,4; 3:; addi 1,1,16"
extern "C" void f_801F4A40() {}
