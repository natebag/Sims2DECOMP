// 0x80019EA8 ESimsCam::CalcZAxisTheta(EVec3 (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lfs f13,0x0(3); addi 11,1,8; lfs f0,0x4(3); lis 9,-32707; lfs f12,0x8(3); stfs f13,0x8(1); stfs f0,0x4(11); stfs f12,0x8(11); lfs f13,-7144(9); lfs f0,0x8(1); stfs f13,0x10(1); fcmpu 0,f0,f13; bne 0f; lfs f0,0x4(11); fcmpu 0,f0,f13; bne 0f; lfs f0,0x8(11); fcmpu 0,f0,f13; beq 1f; 0:; mr 3,11; mr 4,3; bl _s80019EA8_0; 1:; lis 9,-32707; lfs f1,0x8(1); lfs f0,-7140(9); fcmpu 0,f1,f0; ble 2f; fmr f1,f0; 2:; lis 9,-32707; lfs f0,-7136(9); fcmpu 0,f1,f0; bge 3f; fmr f1,f0; 3:; bl _s80019EA8_1; lis 9,-32707; lfs f13,0xc(1); lfs f0,-7144(9); fcmpu 0,f13,f0; bge 4f; lis 9,-32707; lfs f0,-7132(9); fsubs f1,f0,f1; 4:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s80019EA8_0();
extern "C" void _s80019EA8_1();
extern "C" void f_80019EA8() {}
