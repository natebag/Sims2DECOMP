// 0x801E46AC WAFTarget::CalculateTweenTargetPosition(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x278(3); li 0,1; lfs f0,0x274(3); fcmpu 0,f0,f13; bge 0f; li 0,0; 0:; cmpwi 0,0; beq 3f; lis 9,-32705; lfs f12,0x64c4(9); fcmpu 0,f13,f12; bge 2f; 1:; fmr f1,f0; fcmpu 0,f0,f12; bltlr; fmr f1,f12; blr; 2:; lis 9,-32705; lfs f12,0x64c8(9); fcmpu 0,f13,f12; blt 1b; fmr f1,f0; blr; 3:; lis 9,-32705; lfs f12,0x64c8(9); fcmpu 0,f13,f12; ble 5f; 4:; fmr f1,f0; fcmpu 0,f0,f12; bgtlr; fmr f1,f12; blr; 5:; lis 9,-32705; lfs f12,0x64c4(9); fcmpu 0,f13,f12; bgt 4b; lis 9,-32705; fmr f1,f0; lfs f13,0x64cc(9); fcmpu 0,f0,f13; bgtlr; fmr f1,f13"
extern "C" float f_801E46AC() {}
