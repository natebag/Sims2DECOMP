// 0x800123D4 AwarenessManager::GetSecondNodeRotation(float) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); lis 9,-32707; addi 11,1,8; lfs f0,-9064(9); addi 10,1,24; lis 9,-32707; mr 30,11; lfs f13,-9060(9); mr 0,10; stfs f0,0x8(11); mr 31,3; stfs f0,0x4(11); fmr f12,f0; stfs f0,0x8(1); stfs f13,0xc(11); stfs f0,0x18(1); stfs f13,0x8(10); stfs f0,0x4(10); lfs f13,0xc(4); fcmpu 0,f13,f1; ble 0f; fsubs f12,f13,f1; b 1f; 0:; fneg f0,f1; fcmpu 0,f13,f0; bge 1f; fadds f12,f13,f1; 1:; fmr f1,f12; mr 4,0; addi 3,1,8; bl _s800123D4_0; lfs f11,0xc(30); mr 3,31; lfs f0,0x8(1); lfs f13,0x4(30); lfs f12,0x8(30); stfs f0,0x0(31); stfs f13,0x4(31); stfs f12,0x8(31); stfs f11,0xc(31); lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s800123D4_0();
extern "C" void f_800123D4() {}
