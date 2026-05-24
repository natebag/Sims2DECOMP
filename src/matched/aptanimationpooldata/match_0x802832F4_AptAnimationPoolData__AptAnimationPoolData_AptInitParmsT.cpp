// 0x802832F4 AptAnimationPoolData::AptAnimationPoolData(AptInitParmsT (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 28,4; mr 31,3; lwz 0,0x0(28); addi 30,31,8; lwz 3,-23020(13); li 26,0; rlwinm 4,0,2,14,29; sth 0,0x2(30); bl _s802832F4_0; addi 29,31,24; stw 3,0x4(30); li 4,0; sth 26,0x8(31); addi 27,31,32; lhz 5,0x2(30); lwz 3,0x4(30); rlwinm 5,5,2,0,29; bl _s802832F4_1; lwz 0,0x8(28); lwz 3,-23020(13); rlwinm 4,0,2,14,29; sth 0,0x2(29); bl _s802832F4_2; stw 3,0x4(29); li 4,0; sth 26,0x18(31); lhz 5,0x2(29); lwz 3,0x4(29); rlwinm 5,5,2,0,29; bl _s802832F4_3; lwz 0,0x4(28); lwz 3,-23020(13); rlwinm 4,0,2,14,29; sth 0,0x2(27); bl _s802832F4_4; stw 3,0x4(27); li 4,0; sth 26,0x20(31); lhz 5,0x2(27); lwz 3,0x4(27); rlwinm 5,5,2,0,29; bl _s802832F4_5; addi 3,31,40; bl _s802832F4_6; lwz 4,0x18(28); lwz 3,-23020(13); stw 4,0x9c(31); rlwinm 4,4,2,0,29; lwz 0,0x10(28); stw 0,0xa0(31); lwz 9,0x1c(28); stw 9,0xa4(31); lwz 0,0x14(28); stw 0,0xa8(31); bl _s802832F4_7; stw 3,0x0(31); li 4,20; lwz 3,-23020(13); bl _s802832F4_8; lwz 0,0xc(28); mr 30,3; mulli 3,0,20; stw 0,0x10(30); bl _s802832F4_9; mr 0,3; mr 3,30; stw 0,0x4(30); stw 0,0x0(30); stw 0,0x8(30); bl _s802832F4_10; lwz 3,0xa8(31); stw 30,0x98(31); cmpwi 3,0; beq 0f; mulli 3,3,28; bl _s802832F4_11; 0:; stw 3,0x14(31); lwz 30,0xa0(31); rlwinm 3,30,5,0,26; addi 28,30,-1; ori 3,3,8; bl _s802832F4_12; addi 26,3,8; cmpwi 30,0; stw 30,-8(26); beq 2f; lis 9,-32704; addi 30,3,28; lwz 27,0x2e0c(9); li 29,0; li 25,6; 1:; stw 29,-20(30); li 4,24; stw 29,-16(30); stw 27,-12(30); stw 27,-8(30); stw 29,0x0(30); stw 25,0x4(30); stw 29,0x8(30); lwz 3,-23020(13); bl _s802832F4_13; stw 3,0x8(30); cmpwi 28,0; addi 30,30,32; addi 28,28,-1; bne 1b; 2:; lwz 4,0xa4(31); stw 26,0x2c(31); lwz 3,-23020(13); rlwinm 4,4,2,0,29; bl _s802832F4_14; lwz 9,-22936(13); li 0,0; stw 3,0x38(31); stw 0,0x94(31); mr 3,31; stw 9,0x60(31); stw 0,0x4(31); stw 0,0x34(31); stw 0,0x64(31); stw 0,0x68(31); stw 0,0x10(31); stw 0,0x6c(31); stw 0,0x70(31); stw 0,0x30(31); stw 9,0x3c(31); stw 9,0x58(31); stw 9,0x5c(31); lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s802832F4_0();
extern "C" void _s802832F4_1();
extern "C" void _s802832F4_2();
extern "C" void _s802832F4_3();
extern "C" void _s802832F4_4();
extern "C" void _s802832F4_5();
extern "C" void _s802832F4_6();
extern "C" void _s802832F4_7();
extern "C" void _s802832F4_8();
extern "C" void _s802832F4_9();
extern "C" void _s802832F4_10();
extern "C" void _s802832F4_11();
extern "C" void _s802832F4_12();
extern "C" void _s802832F4_13();
extern "C" void _s802832F4_14();

struct AptAnimationPoolData {
    void AptAnimationPoolData_AptInitParmsT();
};

void AptAnimationPoolData::AptAnimationPoolData_AptInitParmsT() {
}
