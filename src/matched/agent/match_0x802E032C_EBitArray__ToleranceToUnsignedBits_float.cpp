// 0x802E032C EBitArray::ToleranceToUnsignedBits(float) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); li 0,3; xoris 0,0,32768; lis 10,17200; stw 0,0xc(1); lis 9,-32702; lfd f13,-6432(9); lis 11,-32702; stw 10,0x8(1); li 3,2; lfs f12,-6424(11); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f12,f0; fcmpu 0,f0,f1; cror 3,2,0; bso 1f; li 10,1; lis 11,17200; 0:; addi 3,3,1; cmpwi 3,31; bgt 1f; slw 9,10,3; addi 9,9,-1; xoris 0,9,32768; stw 0,0xc(1); stw 11,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f12,f0; fcmpu 0,f0,f1; cror 3,2,0; bns 0b; 1:; addi 1,1,16"
extern "C" void f_802E032C() {}
