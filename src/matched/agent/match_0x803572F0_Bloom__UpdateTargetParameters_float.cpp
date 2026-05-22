// 0x803572F0 Bloom::UpdateTargetParameters(float) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0xc(31); cmpwi 0,2; bne 2f; lfs f0,0x14(31); lis 9,-32702; fmr f5,f1; lfs f3,0x2ae0(9); lfs f1,0x70(31); lfs f2,0x18(31); lfs f4,0x0(31); stfs f0,0x40(31); bl _s803572F0_0; lfs f0,0x1c(31); addi 8,31,32; stfs f1,0x44(31); addi 10,31,76; stfs f0,0x48(31); li 11,0; 0:; rlwinm 9,11,3,0,28; addi 0,11,1; li 11,2; mtspr 9,11; 1:; lfsx f0,9,8; stfsx f0,9,10; addi 9,9,4; bdnz 1b; mr 11,0; cmpwi 11,3; ble 0b; b 3f; 2:; cmpwi 0,8; bne 3f; lis 9,-32702; lis 11,-32702; fmr f5,f1; lfs f2,0x2ae4(9); lfs f3,0x2ae0(11); lfs f1,0x70(31); lfs f4,0x4(31); bl _s803572F0_1; stfs f1,0x44(31); 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803572F0_0();
extern "C" void _s803572F0_1();
extern "C" void f_803572F0() {}
