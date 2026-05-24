// 0x802EC198 EAnimController::CreateStreams(EACTrack (796 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stfd f31,0x40(1); stmw 22,0x18(1); stw 0,0x4c(1); mr 22,3; mr. 28,4; beq 22f; lwz 0,0x7c(28); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 22f; lwz 9,0x24(22); cmpwi 9,0; li 25,0; beq 1f; lwz 25,0x18(9); 1:; rlwinm. 31,25,5,0,26; beq 2f; bl _s802EC198_0; mr 4,31; li 5,0; bl _s802EC198_1; stw 3,0x98(28); b 3f; 2:; stw 31,0x98(28); 3:; lwz 0,0x98(28); cmpwi 0,0; beq 22f; li 24,0; cmpw 24,25; bge 21f; li 27,0; li 26,0; li 23,0; 4:; lwz 9,0x7c(28); lwz 31,0x98(28); lwz 11,0x34(9); add 29,31,26; add 30,11,23; lwz 0,0x4(30); cmpwi 0,0; bge 5f; li 3,112; bl _s802EC198_2; stw 27,0x0(3); cmpwi 3,0; stwx 3,31,26; beq 22f; lwz 4,0x7c(28); lwz 5,0x4(30); addi 4,4,80; neg 5,5; bl _s802EC198_3; b 6f; 5:; stwx 27,31,26; 6:; lwz 0,0xc(30); cmpwi 0,0; bge 7f; li 3,116; bl _s802EC198_4; stw 27,0x0(3); cmpwi 3,0; stw 3,0x4(29); beq 22f; lwz 4,0x7c(28); lwz 5,0xc(30); addi 4,4,80; neg 5,5; bl _s802EC198_5; b 8f; 7:; stw 27,0x4(29); 8:; lwz 0,0x8(30); cmpwi 0,0; bge 9f; li 3,116; bl _s802EC198_6; stw 27,0x0(3); cmpwi 3,0; stw 3,0x8(29); beq 22f; lwz 4,0x7c(28); lwz 5,0x8(30); addi 4,4,80; neg 5,5; bl _s802EC198_7; b 10f; 9:; stw 27,0x8(29); 10:; lwz 0,0x10(30); cmpwi 0,0; bge 11f; li 3,12; bl _s802EC198_8; stw 27,0x0(3); cmpwi 3,0; stw 3,0xc(29); beq 22f; lwz 4,0x7c(28); lwz 5,0x10(30); addi 4,4,80; neg 5,5; bl _s802EC198_9; b 12f; 11:; stw 27,0xc(29); 12:; lwz 0,0x14(30); cmpwi 0,0; bge 13f; li 3,116; bl _s802EC198_10; stw 27,0x0(3); cmpwi 3,0; stw 3,0x10(29); beq 22f; lwz 4,0x7c(28); lwz 5,0x14(30); addi 4,4,80; neg 5,5; bl _s802EC198_11; b 14f; 13:; stw 27,0x10(29); 14:; lwz 0,0x18(30); cmpwi 0,0; bge 15f; li 3,68; bl _s802EC198_12; stw 27,0x0(3); cmpwi 3,0; stw 3,0x14(29); beq 22f; lwz 4,0x7c(28); lwz 5,0x18(30); addi 4,4,80; neg 5,5; bl _s802EC198_13; b 16f; 15:; stw 27,0x14(29); 16:; lwz 0,0x1c(30); cmpwi 0,0; bge 17f; li 3,68; bl _s802EC198_14; stw 27,0x0(3); cmpwi 3,0; stw 3,0x18(29); beq 22f; lwz 4,0x7c(28); lwz 5,0x1c(30); addi 4,4,80; neg 5,5; bl _s802EC198_15; b 18f; 17:; stw 27,0x18(29); 18:; lwz 0,0x20(30); cmpwi 0,0; bge 19f; li 3,68; bl _s802EC198_16; stw 27,0x0(3); cmpwi 3,0; stw 3,0x1c(29); beq 22f; lwz 5,0x20(30); lwz 4,0x7c(28); neg 5,5; addi 4,4,80; bl _s802EC198_17; b 20f; 19:; stw 27,0x1c(29); 20:; addi 24,24,1; addi 26,26,32; addi 23,23,36; cmpw 24,25; blt 4b; 21:; lis 9,-32702; lfs f31,0x40(28); lfs f0,-4520(9); mr 4,22; addi 3,1,8; mr 5,28; stfs f0,0x40(28); bl _s802EC198_18; lwz 8,0x8(1); addi 9,1,8; lwz 10,0x8(9); addi 11,28,128; lwz 0,0x4(9); stw 8,0x80(28); stw 10,0x8(11); stw 0,0x4(11); stfs f31,0x40(28); 22:; lwz 0,0x4c(1); mtspr 8,0; lmw 22,0x18(1); lfd f31,0x40(1); addi 1,1,72"

extern "C" void _s802EC198_0();
extern "C" void _s802EC198_1();
extern "C" void _s802EC198_2();
extern "C" void _s802EC198_3();
extern "C" void _s802EC198_4();
extern "C" void _s802EC198_5();
extern "C" void _s802EC198_6();
extern "C" void _s802EC198_7();
extern "C" void _s802EC198_8();
extern "C" void _s802EC198_9();
extern "C" void _s802EC198_10();
extern "C" void _s802EC198_11();
extern "C" void _s802EC198_12();
extern "C" void _s802EC198_13();
extern "C" void _s802EC198_14();
extern "C" void _s802EC198_15();
extern "C" void _s802EC198_16();
extern "C" void _s802EC198_17();
extern "C" void _s802EC198_18();

struct EAnimController {
    void CreateStreams();
};

void EAnimController::CreateStreams() {
}
