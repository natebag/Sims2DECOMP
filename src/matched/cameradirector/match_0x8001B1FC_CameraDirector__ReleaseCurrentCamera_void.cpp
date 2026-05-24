// 0x8001B1FC CameraDirector::ReleaseCurrentCamera(void) (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x240(31); rlwinm 0,0,0,0,30; stw 0,0x240(31); bl _s8001B1FC_0; lwz 9,0x170(31); cmpwi 9,0; beq 0f; lwz 9,0x0(9); li 4,-1; lfs f0,0x17c(31); stfs f0,0x64(9); lwz 11,0x170(31); lfs f0,0x178(31); lwz 9,0x0(11); stfs f0,0x60(9); lwz 11,0x170(31); lfs f0,0x180(31); lwz 9,0x0(11); stfs f0,0x70(9); lwz 11,0x170(31); lfs f0,0x184(31); lwz 9,0x0(11); stfs f0,0x6c(9); lwz 3,0x170(31); bl _s8001B1FC_1; 0:; lis 9,-32707; li 30,0; lfs f31,-6928(9); li 0,1; stw 30,0x160(31); addi 3,31,128; stw 30,0x164(31); stw 30,0x24c(31); stw 30,0x170(31); stfs f31,0x194(31); stfs f31,0x190(31); stw 30,0x198(31); stfs f31,0x22c(31); stw 30,0x220(31); stfs f31,0x224(31); stfs f31,0x228(31); stw 0,0x230(31); bl _s8001B1FC_2; stfs f31,0x1a0(31); fmr f1,f31; stw 30,0x118(31); fmr f2,f31; stw 30,0x11c(31); fmr f3,f31; lwz 11,-26392(13); fmr f4,f31; lwz 9,0x0(11); lwz 0,0x1ac(9); lha 3,0x1a8(9); mtspr 8,0; add 3,11,3; blrl; lis 9,-32707; lis 11,-32707; fmr f1,f31; lwz 3,-26392(13); lfs f3,-6924(9); fmr f2,f1; lfs f4,-6920(11); bl _s8001B1FC_3; lwz 0,0x31c(31); mr 3,31; stw 30,0x248(31); li 4,0; rlwinm 0,0,0,0,29; stw 0,0x31c(31); bl _s8001B1FC_4; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"

extern "C" void _s8001B1FC_0();
extern "C" void _s8001B1FC_1();
extern "C" void _s8001B1FC_2();
extern "C" void _s8001B1FC_3();
extern "C" void _s8001B1FC_4();

struct CameraDirector {
    void ReleaseCurrentCamera();
};

void CameraDirector::ReleaseCurrentCamera() {
}
