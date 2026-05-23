// 0x80065818 SAnimator2::eventHandler(EAnimNote (848 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); lwz 11,-21508(13); li 0,0; mr 31,3; mr 30,4; lwz 9,0x0(11); stw 0,0x8(1); lwz 0,0x174(9); lha 3,0x170(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); mr 29,3; cmpwi 0,8; beq 24f; bgt 1f; cmpwi 0,4; bgt 0f; cmpwi 0,2; bge 24f; cmpwi 0,0; beq 24f; cmpwi 0,1; beq 3f; b 24f; 0:; cmpwi 0,6; beq 5f; bgt 17f; b 4f; 1:; cmpwi 0,12; bgt 2f; cmpwi 0,11; bge 24f; cmpwi 0,9; beq 18f; cmpwi 0,10; beq 19f; b 24f; 2:; cmpwi 0,14; beq 21f; blt 22f; cmpwi 0,15; beq 23f; b 24f; 3:; lwz 4,0x8(30); mr 3,31; bl _s80065818_0; b 24f; 4:; lwz 9,0x4(31); lwz 29,0x8(30); lwz 11,0x0(9); lwz 30,-21492(13); lwz 9,0x4(11); lha 3,0x328(9); lwz 0,0x32c(9); add 3,11,3; mtspr 8,0; blrl; mr 5,3; mr 4,29; mr 3,30; bl _s80065818_1; b 24f; 5:; lwz 3,0x8(30); addi 27,1,8; addi 29,31,220; bl _s80065818_2; lwz 30,0x4(29); lwz 0,0xc(29); stw 3,0x8(1); cmpw 30,0; beq 6f; stw 3,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 24f; 6:; lwz 0,0xdc(31); li 9,1; stw 9,0x10(1); addi 11,1,16; subf 0,0,30; addi 9,1,12; srawi 3,0,2; stw 3,0xc(1); cmplwi 3,1; bge 7f; mr 9,11; 7:; lwz 0,0x0(9); add. 0,3,0; beq 9f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 8f; mr 3,28; bl _s80065818_3; mr 31,3; b 10f; 8:; mr 3,28; bl _s80065818_4; mr 31,3; b 10f; 9:; li 31,0; li 28,0; 10:; lwz 4,0x0(29); cmpw 30,4; beq 11f; subf 30,4,30; mr 3,31; mr 5,30; bl _s80065818_5; add 0,3,30; b 12f; 11:; mr 0,31; 12:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 14f; 13:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 13b; 14:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 16f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 15f; bl _s80065818_6; b 16f; 15:; bl _s80065818_7; 16:; add 0,28,31; stw 31,0x0(29); stw 0,0xc(29); stw 30,0x4(29); b 24f; 17:; lis 4,-32707; mr 3,29; addi 4,4,19028; bl _s80065818_8; mr 4,3; lwz 5,0x8(30); mr 3,29; bl _s80065818_9; mr. 4,3; beq 24f; mr 3,31; bl _s80065818_10; b 24f; 18:; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; bl _s80065818_11; lwz 11,0x0(3); lwz 9,0x18(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; b 24f; 19:; lwz 4,0x8(30); lis 3,-32692; addi 3,3,-4004; li 5,0; li 6,0; bl _s80065818_12; mr. 30,3; beq 24f; lwz 9,0x14(30); lwz 0,0x18(30); subf 0,9,0; rlwinm. 9,0,29,3,31; beq 20f; mr 3,31; mr 4,30; bl _s80065818_13; 20:; mr 3,30; bl _s80065818_14; b 24f; 21:; lwz 3,0x4(31); mr 4,30; li 5,14; bl _s80065818_15; b 24f; 22:; lwz 3,0x4(31); mr 4,30; li 5,13; bl _s80065818_16; b 24f; 23:; lwz 3,0x4(31); mr 4,30; li 5,15; bl _s80065818_17; 24:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s80065818_0();
extern "C" void _s80065818_1();
extern "C" void _s80065818_2();
extern "C" void _s80065818_3();
extern "C" void _s80065818_4();
extern "C" void _s80065818_5();
extern "C" void _s80065818_6();
extern "C" void _s80065818_7();
extern "C" void _s80065818_8();
extern "C" void _s80065818_9();
extern "C" void _s80065818_10();
extern "C" void _s80065818_11();
extern "C" void _s80065818_12();
extern "C" void _s80065818_13();
extern "C" void _s80065818_14();
extern "C" void _s80065818_15();
extern "C" void _s80065818_16();
extern "C" void _s80065818_17();

struct SAnimator2 {
    void eventHandler_EAnimNote();
};

void SAnimator2::eventHandler_EAnimNote() {
}
