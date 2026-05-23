// 0x8005FDBC SAnimator2::followMiddleUpdate(float (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 25,0x14(1); stw 0,0x3c(1); mr 31,3; lis 9,-32707; lwz 11,0xc(31); mr 27,4; lfs f0,0x474c(9); mr 28,5; lwz 9,0x0(11); li 25,0; lwz 0,0x4(11); fcmpu 0,f1,f0; stfs f1,0x8(1); lis 26,-32707; subf 0,9,0; srawi 29,0,3; ble 3f; lwz 9,0x14(31); addi 0,29,-1; mr 30,0; cmpw 9,0; bge 4f; 0:; lwz 0,0x1c8(31); cmpw 9,0; ble 1f; mr 3,31; addi 4,1,8; bl _s8005FDBC_0; 1:; lfs f0,0x8(1); lfs f31,0x474c(26); fcmpu 0,f0,f31; ble 2f; lwz 9,0x14(31); mr 3,31; addi 9,9,1; stw 9,0x14(31); bl _s8005FDBC_1; fmr f0,f1; mr 3,31; stfs f0,0x0(27); bl _s8005FDBC_2; stfs f1,0x0(28); 2:; lfs f0,0x8(1); fcmpu 0,f0,f31; ble 3f; lwz 9,0x14(31); cmpw 9,30; blt 0b; 3:; lwz 9,0x14(31); addi 0,29,-1; cmpw 9,0; blt 5f; 4:; li 25,1; 5:; mr 3,25; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x14(1); lfd f31,0x30(1); addi 1,1,56"

extern "C" void _s8005FDBC_0();
extern "C" void _s8005FDBC_1();
extern "C" void _s8005FDBC_2();

struct SAnimator2 {
    void followMiddleUpdate();
};

void SAnimator2::followMiddleUpdate() {
}
