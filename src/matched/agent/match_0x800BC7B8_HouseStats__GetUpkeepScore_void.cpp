// 0x800BC7B8 HouseStats::GetUpkeepScore(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 11,0x24(3); cmpwi 11,0; bne 0f; li 3,0; b 3f; 0:; lwz 0,0x20(3); lis 7,17200; mr 8,9; subf 0,0,11; xoris 6,11,32768; xoris 0,0,32768; lis 11,-32706; stw 0,0xc(1); lis 10,-32706; lfd f12,-25072(11); stw 7,0x8(1); lfs f11,-25064(10); lfd f13,0x8(1); stw 6,0xc(1); fsub f13,f13,f12; stw 7,0x8(1); frsp f13,f13; lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; fdivs f12,f13,f0; fcmpu 0,f12,f11; bge 1f; fmr f12,f11; 1:; lis 9,-32706; lfs f0,-25060(9); fcmpu 0,f12,f0; ble 2f; fmr f12,f0; 2:; lis 9,-32706; lfs f0,-25056(9); fmuls f0,f12,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); 3:; addi 1,1,16"
extern "C" void f_800BC7B8() {}
