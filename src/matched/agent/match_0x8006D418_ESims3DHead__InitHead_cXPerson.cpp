// 0x8006D418 ESims3DHead::InitHead(cXPerson (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lfs f13,-32276(13); mr 31,3; lfs f12,-21192(13); stw 4,0x350(31); fcmpu 0,f13,f12; cror 3,2,0; bso 0f; lfs f0,-21184(13); fcmpu 0,f13,f0; cror 3,2,1; bso 0f; lfs f13,-32272(13); lfs f0,-21188(13); fcmpu 0,f13,f0; cror 3,2,0; bso 0f; lfs f0,-21180(13); fcmpu 0,f13,f0; 0:; lis 9,-32707; lfs f1,-32288(13); lfs f2,0x50e0(9); mr 3,31; lfs f3,-32284(13); lfs f4,-32280(13); bl _s8006D418_0; lis 9,-32707; lis 11,-32707; lis 10,-32707; lfs f13,0x50e4(9); lfs f12,0x50e8(11); lfs f0,0x50ec(10); stfs f13,0x398(31); stfs f0,0x3a0(31); stfs f12,0x39c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8006D418_0();
extern "C" void f_8006D418() {}
