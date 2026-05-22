// 0x800A4A24 IsoToAlt(float (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-24592(13); mr 31,3; cmpwi 0,0; bne 0f; lis 9,-32706; lfs f1,-28592(9); bl _s800A4A24_0; li 0,1; fadd f1,f1,f1; stw 0,-24592(13); frsp f1,f1; stfs f1,-24596(13); 0:; lfs f0,0x0(31); lfs f1,-24596(13); fmuls f1,f0,f1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800A4A24_0();
extern "C" void f_800A4A24() {}
