// 0x800A49B8 AltToIso(float (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-24600(13); mr 31,3; cmpwi 0,0; bne 0f; lis 9,-32706; lfs f1,-28608(9); bl _s800A49B8_0; lis 9,-32706; fadds f1,f1,f1; lfd f0,-28600(9); li 0,1; fdiv f0,f0,f1; stw 0,-24600(13); frsp f0,f0; stfs f0,-24604(13); 0:; lfs f0,0x0(31); lfs f1,-24604(13); fmuls f1,f0,f1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800A49B8_0();
extern "C" void f_800A49B8() {}
