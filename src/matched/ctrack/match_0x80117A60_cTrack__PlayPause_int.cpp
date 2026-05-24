// 0x80117A60 cTrack::PlayPause(int, (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 27,0xc(1); stw 0,0x2c(1); mr 31,3; fmr f31,f1; lwz 0,0x34(31); mr 27,4; mr 28,5; mr 29,6; cmpwi 0,0; stfs f31,0x4c(31); beq 1f; lwz 9,0x0(31); lbz 0,0x1d(9); cmpwi 0,1; beq 4f; lwz 0,0x38(31); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 1f; li 0,1; mr 3,31; stw 0,0x38(31); bl _s80117A60_0; b 5f; 1:; mr 3,31; bl _s80117A60_1; mr 4,3; cmpwi 4,2; beq 2f; lwz 3,-24136(13); bl _s80117A60_2; mr. 3,3; beq 2f; lwz 0,0x4(3); cmpwi 0,0; beq 4f; 2:; li 4,0; li 5,32; addi 3,31,84; li 30,0; bl _s80117A60_3; stw 30,0x80(31); li 4,1; stw 30,0x88(31); mr 5,27; stw 30,0x8c(31); mr 3,31; stw 30,0x90(31); stw 30,0x84(31); stw 29,0x78(31); bl _s80117A60_4; li 4,2; mr 5,28; mr 3,31; bl _s80117A60_5; mr 5,29; li 4,3; mr 3,31; bl _s80117A60_6; stw 30,0x38(31); mr 5,28; mr 3,31; li 4,9; bl _s80117A60_7; lwz 9,0x0(31); lbz 0,0x15(9); cmpwi 0,0; beq 3f; blt 3f; cmpwi 0,2; bgt 3f; stw 27,0x4(31); 3:; mr 3,31; bl _s80117A60_8; cmpwi 3,0; beq 4f; lwz 4,0x7c(31); fmr f1,f31; mr 3,31; addi 30,31,28; bl _s80117A60_9; mr 3,31; bl _s80117A60_10; mr 3,31; bl _s80117A60_11; mr 4,3; mr 3,30; bl _s80117A60_12; mr 4,30; addi 3,31,36; bl _s80117A60_13; lwz 9,-24136(13); li 11,1; mr 3,31; lwz 0,0x14(9); stw 11,0x34(31); stw 0,0x18(31); bl _s80117A60_14; 4:; li 3,1; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0xc(1); lfd f31,0x20(1); addi 1,1,40"

extern "C" void _s80117A60_0();
extern "C" void _s80117A60_1();
extern "C" void _s80117A60_2();
extern "C" void _s80117A60_3();
extern "C" void _s80117A60_4();
extern "C" void _s80117A60_5();
extern "C" void _s80117A60_6();
extern "C" void _s80117A60_7();
extern "C" void _s80117A60_8();
extern "C" void _s80117A60_9();
extern "C" void _s80117A60_10();
extern "C" void _s80117A60_11();
extern "C" void _s80117A60_12();
extern "C" void _s80117A60_13();
extern "C" void _s80117A60_14();

struct cTrack {
    void PlayPause();
};

void cTrack::PlayPause() {
}
