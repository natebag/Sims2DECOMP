// 0x8001709C ESimsCam::HandleRotation(void) (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; mfcr 12; stfd f30,0x48(1); stfd f31,0x50(1); stmw 30,0x40(1); stw 0,0x5c(1); stw 12,0x3c(1); mr 31,3; bl _s8001709C_0; lis 9,-32707; lfs f0,-7364(9); fcmpu 0,f1,f0; bge 0f; fneg f0,f1; fmuls f30,f1,f0; b 1f; 0:; fmuls f30,f1,f1; 1:; lwz 9,0x0(31); fabs f13,f30; lfs f0,0x7c(9); lfs f31,0x74(9); fmuls f0,f0,f0; fcmpu 0,f13,f0; ble 2f; lfs f31,0x78(9); 2:; lwz 3,0x4(31); bl _s8001709C_1; cmpwi 3,0; bne 3f; lwz 3,0x4(31); bl _s8001709C_2; cmpwi 3,0; beq 4f; 3:; lis 9,-32697; lwz 11,0x5f14(9); lwz 0,0x24(11); b 5f; 4:; lis 9,-32697; lwz 11,0x5f14(9); lwz 0,0x18(11); 5:; cmpwi 0,0; beq 6f; fneg f31,f31; 6:; lfs f0,-26800(13); lis 9,-32707; lfs f13,-7364(9); fmuls f0,f30,f0; fmuls f31,f0,f31; fcmpu 4,f31,f13; beq cr4,11f; li 0,0; fmr f1,f31; stw 0,0x474(31); mr 3,31; bl _s8001709C_3; li 30,0; addi 3,1,8; mr 4,31; bl _s8001709C_4; mr 3,31; addi 4,1,8; bl _s8001709C_5; cmpwi 3,0; beq 7f; lis 9,-32697; lwz 11,0x4(31); addi 9,9,24012; addi 9,9,280; rlwinm 11,11,2,0,29; lwzx 10,9,11; lwz 0,0x160(10); xori 0,0,8; subfic 9,0,0; adde 0,9,0; xori 30,0,1; 7:; cmpwi 30,0; beq 10f; lwz 3,0x550(31); bl _s8001709C_6; cmpwi 3,0; bne 10f; addi 3,1,40; mr 4,31; bl _s8001709C_7; addi 30,31,1084; lfs f12,0x4(30); addi 3,1,24; lfs f13,0x8(30); lfs f0,0x43c(31); lfs f11,0x28(1); lfs f10,0x2c(1); lfs f9,0x30(1); fsubs f0,f0,f11; fsubs f12,f12,f10; stfs f0,0x18(1); fsubs f13,f13,f9; stfs f12,0x1c(1); stfs f13,0x20(1); bl _s8001709C_8; lfs f13,0x420(31); lis 9,-32707; lfs f0,-7360(9); fdivs f1,f1,f13; fcmpu 0,f1,f0; bge 10f; bge cr4,8f; lis 9,-32707; fneg f13,f31; lfs f0,-7356(9); fmuls f1,f13,f0; b 9f; 8:; lis 9,-32707; lfs f0,-7356(9); fmuls f1,f31,f0; 9:; lfs f13,0x18(1); lfs f0,0x43c(31); fmuls f13,f1,f13; lfs f12,0x1c(1); lfs f11,0x20(1); fsubs f0,f0,f13; stfs f0,0x43c(31); fmuls f12,f1,f12; stfs f13,0x28(1); fmuls f11,f1,f11; lfs f13,0x8(30); lfs f0,0x4(30); stfs f12,0x2c(1); fsubs f13,f13,f11; fsubs f0,f0,f12; stfs f13,0x8(30); stfs f0,0x4(30); stfs f11,0x30(1); 10:; li 3,1; b 12f; 11:; li 0,1; li 3,0; stw 0,0x474(31); 12:; lwz 0,0x5c(1); lwz 12,0x3c(1); mtspr 8,0; lmw 30,0x40(1); lfd f30,0x48(1); lfd f31,0x50(1); mtcrf 8,12; addi 1,1,88"

extern "C" void _s8001709C_0();
extern "C" void _s8001709C_1();
extern "C" void _s8001709C_2();
extern "C" void _s8001709C_3();
extern "C" void _s8001709C_4();
extern "C" void _s8001709C_5();
extern "C" void _s8001709C_6();
extern "C" void _s8001709C_7();
extern "C" void _s8001709C_8();

struct ESimsCam {
    void HandleRotation();
};

void ESimsCam::HandleRotation() {
}
