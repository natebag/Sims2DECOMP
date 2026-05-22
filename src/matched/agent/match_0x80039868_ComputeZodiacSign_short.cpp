// 0x80039868 ComputeZodiacSign(short (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 0,0x2c(1); li 0,5; lis 10,-32707; lis 9,-32707; mtspr 9,0; lis 11,-32702; lfs f12,0x1830(10); lfd f13,0x1828(9); addi 6,11,15868; lis 7,17200; addi 8,1,8; li 10,0; 0:; lwzx 9,10,6; add 9,9,9; lhax 0,9,3; xoris 0,0,32768; stw 0,0x24(1); stw 7,0x20(1); lfd f0,0x20(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfsx f0,10,8; addi 10,10,4; bdnz 0b; addi 3,1,8; bl _s80039868_0; lwz 0,0x2c(1); mtspr 8,0; addi 1,1,40"
extern "C" void _s80039868_0();
extern "C" void f_80039868() {}
