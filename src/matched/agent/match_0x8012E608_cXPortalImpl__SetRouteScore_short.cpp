// 0x8012E608 cXPortalImpl::SetRouteScore(short, (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stfd f30,0x38(1); stfd f31,0x40(1); stmw 25,0x1c(1); stw 0,0x4c(1); mr 27,3; mr 26,4; addi 11,27,8; lwz 9,0x8(27); lwz 0,0x4(11); fmr f30,f1; subf 0,9,0; srawi 0,0,2; cmplw 26,0; ble 13f; lis 9,-32706; mr 31,11; lfs f31,-12424(9); addi 25,1,8; 0:; lwz 30,0x4(31); lwz 0,0xc(31); stfs f31,0x8(1); cmpw 30,0; beq 1f; stfs f31,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 12f; 1:; lwz 0,0x8(27); li 9,1; stw 9,0x10(1); addi 10,1,16; subf 0,0,30; addi 11,1,12; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 2f; mr 11,10; 2:; lwz 0,0x0(11); add. 0,9,0; beq 4f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 3f; mr 3,28; bl _s8012E608_0; mr 29,3; b 5f; 3:; mr 3,28; bl _s8012E608_1; mr 29,3; b 5f; 4:; li 29,0; li 28,0; 5:; lwz 4,0x0(31); cmpw 30,4; beq 6f; subf 30,4,30; mr 3,29; mr 5,30; bl _s8012E608_2; add 0,3,30; b 7f; 6:; mr 0,29; 7:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 9f; 8:; lfs f0,0x0(25); stfs f0,0x0(30); addi 30,30,4; bdnz 8b; 9:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 11f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 10f; bl _s8012E608_3; b 11f; 10:; bl _s8012E608_4; 11:; add 0,28,29; stw 29,0x0(31); stw 30,0x4(31); stw 0,0xc(31); 12:; lwz 0,0x4(31); lwz 9,0x8(27); subf 0,9,0; srawi 0,0,2; cmplw 26,0; bgt 0b; 13:; addi 9,26,-1; lwz 11,0x8(27); rlwinm 9,9,2,0,29; stfsx f30,11,9; lwz 0,0x4c(1); mtspr 8,0; lmw 25,0x1c(1); lfd f30,0x38(1); lfd f31,0x40(1); addi 1,1,72"
extern "C" void _s8012E608_0();
extern "C" void _s8012E608_1();
extern "C" void _s8012E608_2();
extern "C" void _s8012E608_3();
extern "C" void _s8012E608_4();
extern "C" void f_8012E608() {}
