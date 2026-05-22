// 0x802270AC EIDirLight::EIDirLight(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802270AC_0; lis 11,-32704; lis 9,-32697; lfs f13,-7008(11); lis 10,-32704; addi 9,9,-29960; lfs f0,-7004(10); stw 9,0x0(30); addi 11,30,172; stfs f13,0xac(30); mr 3,30; stfs f0,0x8(11); stfs f13,0x4(11); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802270AC_0();
extern "C" void f_802270AC() {}
