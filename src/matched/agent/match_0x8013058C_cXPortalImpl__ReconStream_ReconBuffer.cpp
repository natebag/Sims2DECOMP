// 0x8013058C cXPortalImpl::ReconStream(ReconBuffer (664 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stfd f31,0x48(1); stmw 24,0x28(1); stw 0,0x54(1); stw 12,0x24(1); mr 27,3; mr 31,5; mr 24,4; lwz 3,0x0(27); bl _s8013058C_0; cmpwi 31,14; ble 18f; addi 30,27,8; lwz 9,0x8(27); lwz 0,0x4(30); mr 3,24; addi 4,1,8; li 5,1; subf 0,9,0; mr 29,30; srawi 0,0,2; cmpwi 4,31,37; stw 0,0x8(1); bl _s8013058C_1; lwz 0,0x4(30); lwz 9,0x8(27); lwz 11,0x8(1); subf 0,9,0; srawi 0,0,2; cmplw 11,0; bge 1f; mr 10,29; mr 8,29; 0:; lwz 9,0x4(10); addi 9,9,-4; stw 9,0x4(10); lwz 0,0x4(8); lwz 9,0x8(27); lwz 11,0x8(1); subf 0,9,0; srawi 0,0,2; cmplw 11,0; blt 0b; 1:; lwz 0,0x8(27); lwz 9,0x4(29); lwz 11,0x8(1); mr 4,0; subf 9,0,9; srawi 9,9,2; mr 5,11; cmplw 11,9; ble 15f; lis 9,-32706; mr 26,29; lfs f31,-12420(9); addi 25,1,12; 2:; lwz 9,0x4(26); lwz 0,0xc(26); stfs f31,0xc(1); cmpw 9,0; beq 3f; stfs f31,0x0(9); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 14f; 3:; lwz 30,0x4(29); li 9,1; lwz 0,0x8(27); addi 11,1,20; stw 9,0x14(1); addi 10,1,16; subf 0,0,30; srawi 9,0,2; stw 9,0x10(1); cmplwi 9,1; bge 4f; mr 10,11; 4:; lwz 0,0x0(10); add. 0,9,0; beq 6f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 5f; mr 3,28; bl _s8013058C_2; mr 31,3; b 7f; 5:; mr 3,28; bl _s8013058C_3; mr 31,3; b 7f; 6:; li 31,0; li 28,0; 7:; lwz 4,0x0(29); cmpw 30,4; beq 8f; subf 30,4,30; mr 3,31; mr 5,30; bl _s8013058C_4; add 0,3,30; b 9f; 8:; mr 0,31; 9:; lwz 9,0x14(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 11f; 10:; lfs f0,0x0(25); stfs f0,0x0(30); addi 30,30,4; bdnz 10b; 11:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 13f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 12f; bl _s8013058C_5; b 13f; 12:; bl _s8013058C_6; 13:; add 0,28,31; stw 31,0x0(29); stw 30,0x4(29); stw 0,0xc(29); 14:; lwz 0,0x8(27); lwz 9,0x4(29); lwz 11,0x8(1); mr 4,0; subf 9,0,9; srawi 9,9,2; mr 5,11; cmplw 11,9; bgt 2b; 15:; ble cr4,16f; mr 3,24; bl _s8013058C_7; b 18f; 16:; li 31,0; cmpw 31,5; bge 18f; li 30,0; 17:; stw 30,0x18(1); mr 3,24; addi 4,1,24; li 5,1; bl _s8013058C_8; addi 31,31,1; lwz 0,0x8(1); cmpw 31,0; blt 17b; 18:; lwz 0,0x54(1); lwz 12,0x24(1); mtspr 8,0; lmw 24,0x28(1); lfd f31,0x48(1); mtcrf 8,12; addi 1,1,80"
extern "C" void _s8013058C_0();
extern "C" void _s8013058C_1();
extern "C" void _s8013058C_2();
extern "C" void _s8013058C_3();
extern "C" void _s8013058C_4();
extern "C" void _s8013058C_5();
extern "C" void _s8013058C_6();
extern "C" void _s8013058C_7();
extern "C" void _s8013058C_8();
extern "C" void f_8013058C() {}
