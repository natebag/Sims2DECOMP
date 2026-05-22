// 0x802D5BF0 EVec3::FromS8s(signed (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); li 0,3; lis 11,-32702; lis 9,-32702; mtspr 9,0; lfs f12,-6808(11); lis 10,17200; lfd f13,-6816(9); li 11,0; 0:; lbzx 0,4,11; addi 11,11,1; extsb 0,0; xoris 0,0,32768; stw 0,0xc(1); stw 10,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x0(3); addi 3,3,4; bdnz 0b; addi 1,1,16"
extern "C" void f_802D5BF0() {}
