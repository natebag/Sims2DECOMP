// 0x801D745C PCTTarget::PlaceModeCallback(InteractorModule::Interactor::CallbackData (880 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 26,0x10(1); stw 0,0x34(1); mr 27,4; mr 31,3; lwz 0,0x0(27); cmpwi 0,0; beq 1f; cmpwi 0,3; bne 20f; bl _s801D745C_0; lwz 4,0x84(31); bl _s801D745C_1; li 4,1; mr 3,31; bl _s801D745C_2; li 3,0; crxor 6,6,6; bl _s801D745C_3; lis 3,30424; ori 3,3,7210; bl _s801D745C_4; 0:; li 3,1; b 21f; 1:; lwz 11,-21508(13); lwz 4,0x10(27); cmpwi 11,0; bne 2f; li 30,0; b 3f; 2:; lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; 3:; cmpwi 30,0; beq 6f; mr 3,30; bl _s801D745C_5; mr. 3,3; bne 4f; li 3,0; b 5f; 4:; lwz 3,0x38(3); 5:; cmpwi 3,0; bne 7f; 6:; li 26,0; b 8f; 7:; lha 26,0x24(3); 8:; mr 3,30; li 28,0; bl _s801D745C_6; lwz 9,0x38(3); addi 30,1,8; lhz 11,-21224(13); mr 4,30; lha 29,0xa(9); li 5,0; sth 28,0x8(1); lhz 0,-21204(13); sth 11,0x4(30); sth 11,0x2(30); sth 0,0x8(1); sth 29,0xa(1); sth 26,0xc(1); lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x1a4(9); lha 3,0x1a0(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,-21210(13); mr 4,30; lwz 11,-21476(13); li 5,0; sth 0,0x8(1); lwz 9,0x0(11); lwz 0,0x1a4(9); lha 3,0x1a0(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,-21212(13); mr 4,30; sth 29,0xa(1); li 5,0; sth 0,0x8(1); sth 28,0xc(1); lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 29,58; bne 9f; lhz 0,-21198(13); mr 4,30; sth 29,0xa(1); li 5,0; sth 0,0x8(1); sth 28,0xc(1); lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,11,3; mtspr 8,0; blrl; 9:; cmpwi 29,24; bne 10f; lhz 0,-21196(13); mr 4,30; sth 29,0xa(1); li 5,0; sth 0,0x8(1); sth 28,0xc(1); lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,11,3; mtspr 8,0; blrl; 10:; li 3,1; li 29,0; bl _s801D745C_7; lis 9,-32697; fmr f31,f1; lwz 0,0x6188(9); cmpwi 0,0; beq 11f; lwz 0,0x90(31); cmpwi 0,2; beq 11f; li 0,1; stw 0,0x20c(31); b 14f; 11:; li 3,0; bl _s801D745C_8; subf 30,26,3; li 3,0; mr 4,30; bl _s801D745C_9; cmpw 30,26; bge 12f; li 29,0; 12:; mr 3,31; bl _s801D745C_10; lwz 0,0x90(31); stw 3,0x20c(31); cmpwi 0,2; bne 13f; li 0,0; li 29,0; stw 0,0x90(31); b 14f; 13:; lis 3,-30726; ori 3,3,3858; bl _s801D745C_11; 14:; cmpwi 29,0; beq 15f; lis 9,-32705; lfs f0,0x486c(9); fcmpu 0,f31,f0; cror 3,2,1; bns 15f; li 0,1; li 29,0; stw 0,0x23c(31); 15:; lis 9,-32705; lfs f0,0x4870(9); fcmpu 0,f31,f0; ble 18f; lwz 0,0x22c(31); cmpwi 0,0; bne 16f; li 0,1; stw 0,0x234(31); stw 0,0x22c(31); b 18f; 16:; lis 9,-32705; lfs f0,0x4874(9); fcmpu 0,f31,f0; ble 18f; lwz 0,0x230(31); cmpwi 0,0; beq 17f; li 0,1; stw 0,0x240(31); b 18f; 17:; li 0,1; stw 0,0x238(31); stw 0,0x230(31); 18:; stw 29,0xc(27); cmpwi 29,0; bne 0b; lwz 3,0x214(31); cmpwi 3,0; beq 19f; li 4,0; bl _s801D745C_12; 19:; mr 3,31; li 4,1; li 5,1; bl _s801D745C_13; b 0b; 20:; li 3,0; 21:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x10(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s801D745C_0();
extern "C" void _s801D745C_1();
extern "C" void _s801D745C_2();
extern "C" void _s801D745C_3();
extern "C" void _s801D745C_4();
extern "C" void _s801D745C_5();
extern "C" void _s801D745C_6();
extern "C" void _s801D745C_7();
extern "C" void _s801D745C_8();
extern "C" void _s801D745C_9();
extern "C" void _s801D745C_10();
extern "C" void _s801D745C_11();
extern "C" void _s801D745C_12();
extern "C" void _s801D745C_13();

struct PCTTarget {
    void PlaceModeCallback_InteractorModule__Interactor__C();
};

void PCTTarget::PlaceModeCallback_InteractorModule__Interactor__C() {
}
