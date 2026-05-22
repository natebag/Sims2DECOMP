// 0x80039AF0 SetZodiacSign(short (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); rlwinm 0,4,0,16,31; cmplwi 0,12; bgt 1f; addi 7,4,-1; lis 11,-32707; rlwinm 0,7,2,0,29; addi 11,11,6256; add 0,0,7; lis 9,-32707; add 4,0,11; lis 8,-32707; li 0,5; lis 10,-32707; lfd f11,0x1850(9); mtspr 9,0; lfs f10,0x185c(8); lis 9,-32702; lfs f9,0x1858(10); addi 8,9,15868; lis 7,17200; 0:; lbz 0,0x0(4); mr 10,9; lwz 11,0x0(8); extsb 0,0; addi 8,8,4; xoris 0,0,32768; add 11,11,11; stw 0,0xc(1); addi 4,4,1; stw 7,0x8(1); lfd f0,0x8(1); fsub f0,f0,f11; frsp f0,f0; fmadds f0,f0,f9,f10; fmr f13,f0; fctiwz f12,f13; stfd f12,0x8(1); lwz 10,0xc(1); sthx 10,11,3; bdnz 0b; 1:; addi 1,1,16"
extern "C" void f_80039AF0() {}
