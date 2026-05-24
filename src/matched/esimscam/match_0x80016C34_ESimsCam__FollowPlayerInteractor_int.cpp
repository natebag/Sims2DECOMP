// 0x80016C34 ESimsCam::FollowPlayerInteractor(int) (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stfd f31,0x48(1); stmw 29,0x3c(1); stw 0,0x54(1); mr 31,3; bl _s80016C34_0; lwz 4,0x4(31); li 5,-1; bl _s80016C34_1; mr. 3,3; beq 1f; lfs f0,0x8(3); addi 10,3,8; addi 9,1,8; lis 11,-32707; stfs f0,0x8(1); addi 30,31,864; lfs f31,-7380(11); mr 29,9; lfs f13,0x4(10); mr 3,30; mr 4,9; stfs f13,0x4(9); lfs f0,0x8(10); stfs f0,0x8(9); stfs f31,0x10(1); bl _s80016C34_2; cmpwi 3,0; bne 0f; lfs f13,0x4(29); addi 4,1,24; lfs f0,0x8(29); mr 3,30; lfs f12,0x8(1); stfs f13,0x1c(1); stfs f12,0x18(1); stfs f0,0x20(1); bl _s80016C34_3; lfs f11,0x18(1); addi 3,1,40; lfs f12,0x8(1); lfs f13,0x4(29); fsubs f12,f12,f11; lfs f0,0x8(29); lfs f10,0x1c(1); lfs f11,0x20(1); fsubs f13,f13,f10; stfs f12,0x28(1); fsubs f0,f0,f11; stfs f13,0x2c(1); stfs f0,0x30(1); bl _s80016C34_4; fcmpu 0,f1,f31; ble 0f; lis 9,-32697; lfs f12,0x28(1); lfs f10,0x3590(9); addi 11,31,1084; lfs f13,0x43c(31); addi 8,31,1108; lfs f11,0x2c(1); fmuls f12,f12,f10; lfs f0,0x30(1); fadds f13,f13,f12; stfs f13,0x43c(31); fmuls f11,f11,f10; fmuls f0,f0,f10; stfs f12,0x28(1); stfs f0,0x30(1); stfs f11,0x2c(1); lfs f0,0x4(11); lfs f13,0x8(11); fadds f0,f0,f11; stfs f0,0x4(11); lfs f12,0x30(1); lwz 10,0x4(11); fadds f13,f13,f12; stfs f13,0x8(11); lwz 0,0x43c(31); lwz 9,0x8(11); stw 0,0x454(31); stw 9,0x8(8); stw 10,0x4(8); 0:; lwz 10,0x8(1); addi 11,31,1072; lwz 0,0x8(29); lwz 9,0x4(29); stw 10,0x430(31); stw 0,0x8(11); stw 9,0x4(11); 1:; lwz 0,0x54(1); mtspr 8,0; lmw 29,0x3c(1); lfd f31,0x48(1); addi 1,1,80"

extern "C" void _s80016C34_0();
extern "C" void _s80016C34_1();
extern "C" void _s80016C34_2();
extern "C" void _s80016C34_3();
extern "C" void _s80016C34_4();

struct ESimsCam {
    void FollowPlayerInteractor();
};

void ESimsCam::FollowPlayerInteractor() {
}
