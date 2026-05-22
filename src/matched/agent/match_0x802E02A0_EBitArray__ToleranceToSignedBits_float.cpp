// 0x802E02A0 EBitArray::ToleranceToSignedBits(float) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); li 0,1; xoris 0,0,32768; lis 11,17200; stw 0,0xc(1); lis 9,-32702; lfd f13,-6440(9); li 3,2; stw 11,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fcmpu 0,f0,f1; cror 3,2,0; bso 1f; fmr f12,f0; li 8,1; 0:; addi 3,3,1; cmpwi 3,31; bgt 1f; addi 9,3,-1; slw 9,8,9; addi 9,9,-1; xoris 0,9,32768; stw 0,0xc(1); stw 11,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f12,f0; fcmpu 0,f0,f1; cror 3,2,0; bns 0b; 1:; addi 1,1,16"
extern "C" void f_802E02A0() {}
