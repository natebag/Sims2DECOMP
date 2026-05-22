// 0x8029D6A8 AptAnimationPoolData::_pointHits(AptCIH (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 31,0x2c(1); stw 0,0x34(1); mr 31,3; mr 3,4; addi 4,1,8; bl _s8029D6A8_0; lwz 0,0x6c(31); lis 10,17200; lis 11,-32703; xoris 0,0,32768; lfd f11,-30184(11); stw 0,0x24(1); lfs f13,0x8(1); stw 10,0x20(1); lfd f0,0x20(1); fsub f0,f0,f11; frsp f12,f0; fcmpu 0,f12,f13; blt 0f; lfs f0,0x10(1); fcmpu 0,f12,f0; bgt 0f; lwz 0,0x70(31); lfs f13,0xc(1); xoris 0,0,32768; stw 0,0x24(1); stw 10,0x20(1); lfd f0,0x20(1); fsub f0,f0,f11; frsp f12,f0; fcmpu 0,f12,f13; blt 0f; lfs f0,0x14(1); li 3,1; fcmpu 0,f12,f0; cror 3,2,0; bso 1f; 0:; li 3,0; 1:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x2c(1); addi 1,1,48"
extern "C" void _s8029D6A8_0();
extern "C" void f_8029D6A8() {}
