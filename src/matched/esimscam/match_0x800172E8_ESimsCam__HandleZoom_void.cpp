// 0x800172E8 ESimsCam::HandleZoom(void) (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stfd f31,0x48(1); stmw 30,0x40(1); stw 0,0x54(1); stw 12,0x3c(1); mr 31,3; bl _s800172E8_0; lwz 11,0x0(31); lis 9,-32707; lfs f13,-7352(9); lfs f0,0x88(11); fmuls f31,f1,f0; fcmpu 4,f31,f13; beq cr4,4f; fmr f1,f31; mr 3,31; bl _s800172E8_1; li 30,0; addi 3,1,8; mr 4,31; bl _s800172E8_2; mr 3,31; addi 4,1,8; bl _s800172E8_3; cmpwi 3,0; beq 0f; lis 9,-32697; lwz 11,0x4(31); addi 9,9,24012; addi 9,9,280; rlwinm 11,11,2,0,29; lwzx 10,9,11; lwz 0,0x160(10); xori 0,0,8; subfic 9,0,0; adde 0,9,0; xori 30,0,1; 0:; cmpwi 30,0; beq 3f; lwz 3,0x550(31); bl _s800172E8_4; cmpwi 3,0; bne 3f; ble cr4,3f; addi 3,1,40; mr 4,31; bl _s800172E8_5; addi 30,31,1084; lfs f12,0x4(30); addi 3,1,24; lfs f13,0x8(30); lfs f0,0x43c(31); lfs f11,0x28(1); lfs f10,0x2c(1); lfs f9,0x30(1); fsubs f0,f0,f11; fsubs f12,f12,f10; stfs f0,0x18(1); fsubs f13,f13,f9; stfs f12,0x1c(1); stfs f13,0x20(1); bl _s800172E8_6; lfs f13,0x420(31); lis 9,-32707; lfs f0,-7348(9); fdivs f1,f1,f13; fcmpu 0,f1,f0; bge 3f; bge cr4,1f; lfs f13,-32676(13); fneg f0,f31; fmuls f1,f0,f13; b 2f; 1:; lfs f0,-32676(13); fmuls f1,f31,f0; 2:; lfs f13,0x18(1); lfs f0,0x43c(31); fmuls f13,f1,f13; lfs f12,0x1c(1); lfs f11,0x20(1); fsubs f0,f0,f13; stfs f0,0x43c(31); fmuls f12,f1,f12; stfs f13,0x28(1); fmuls f11,f1,f11; lfs f13,0x8(30); lfs f0,0x4(30); stfs f12,0x2c(1); fsubs f13,f13,f11; fsubs f0,f0,f12; stfs f13,0x8(30); stfs f0,0x4(30); stfs f11,0x30(1); 3:; li 3,1; b 5f; 4:; li 3,0; 5:; lwz 0,0x54(1); lwz 12,0x3c(1); mtspr 8,0; lmw 30,0x40(1); lfd f31,0x48(1); mtcrf 8,12; addi 1,1,80"

extern "C" void _s800172E8_0();
extern "C" void _s800172E8_1();
extern "C" void _s800172E8_2();
extern "C" void _s800172E8_3();
extern "C" void _s800172E8_4();
extern "C" void _s800172E8_5();
extern "C" void _s800172E8_6();

struct ESimsCam {
    void HandleZoom();
};

void ESimsCam::HandleZoom() {
}
