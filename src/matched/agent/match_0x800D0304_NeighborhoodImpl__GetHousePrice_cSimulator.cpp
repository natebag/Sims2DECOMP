// 0x800D0304 NeighborhoodImpl::GetHousePrice(cSimulator (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,4; lwz 9,0x0(30); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); mr 29,3; lwz 0,0x134(9); lha 3,0x130(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); mr 28,3; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,30,3; blrl; xoris 3,3,32768; stw 3,0xc(1); lis 0,17200; lis 11,-32706; lfs f13,-24320(13); stw 0,0x8(1); mr 3,9; lfd f12,-21984(11); add 29,29,28; lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; fmuls f13,f13,f0; fctiwz f11,f13; stfd f11,0x8(1); lwz 3,0xc(1); add 3,29,3; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void f_800D0304() {}
