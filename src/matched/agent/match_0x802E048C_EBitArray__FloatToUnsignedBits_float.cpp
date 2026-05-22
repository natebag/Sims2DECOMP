// 0x802E048C EBitArray::FloatToUnsignedBits(float, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); li 9,1; slw 9,9,4; lis 0,17200; addi 9,9,-1; lis 11,-32702; xoris 9,9,32768; lfd f13,-6400(11); stw 9,0xc(1); lis 11,-32702; lfs f12,-6392(11); lis 9,-32702; stw 0,0x8(1); lfs f11,-6388(9); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmadds f13,f1,f0,f12; fcmpu 0,f13,f11; bge 0f; fmr f12,f11; b 1f; 0:; fmr f12,f13; fcmpu 0,f13,f0; ble 1f; fmr f12,f0; 1:; fmr f0,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); addi 1,1,16"
extern "C" void f_802E048C() {}
