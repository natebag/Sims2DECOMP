// 0x80112D40 ObjTestSim::AppendInteractionsForAuto(InteractionList (728 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; mfcr 12; stmw 25,0x54(1); stw 0,0x74(1); stw 12,0x50(1); mr 28,3; mr 25,4; lwz 3,0x4(28); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 11,0x4(28); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 0,0x10(3); cmpwi 0,0; bgt 7f; 0:; lwz 3,0x4(28); lwz 9,0x4(3); lha 0,0x360(9); lwz 9,0x364(9); add 3,3,0; mtspr 8,9; blrl; mr. 27,3; beq 7f; lwz 9,0x0(27); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,27,3; blrl; lwz 11,0x0(28); mr 30,3; lwz 9,0x4(11); lwz 0,0x1d4(9); lha 3,0x1d0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x0(28); mr 29,3; li 4,36; lwz 9,0x4(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; mr 26,3; addic. 31,30,-1; blt 4f; cmpwi 4,29,0; 1:; lwz 9,0x0(27); mr 4,31; lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,27,3; blrl; mr 30,3; lwz 9,0x0(30); lha 3,0x1e0(9); lwz 0,0x1e4(9); add 3,30,3; mtspr 8,0; blrl; beq cr4,2f; andi. 0,3,1; beq 3f; 2:; andi. 0,3,64; bne 3f; lwz 9,0x0(30); lha 3,0xc8(9); lwz 0,0xcc(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; lwz 9,0x0(30); lha 3,0x170(9); lwz 0,0x174(9); add 3,30,3; mtspr 8,0; blrl; cmpw 26,3; blt 3f; lwz 9,0x0(30); lwz 29,0x0(28); lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; lwz 30,0x4(28); blrl; mr 6,3; mr 4,29; mr 5,30; mr 3,25; li 7,0; bl _s80112D40_0; 3:; addic. 31,31,-1; bge 1b; 4:; lwz 3,0x4(28); lwz 9,0x4(3); lha 0,0x318(9); lwz 9,0x31c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,2; bne 7f; lwz 3,0x4(28); cmpwi 3,0; beq 5f; lwz 3,0x0(3); li 4,2; bl _s80112D40_1; mr 31,3; b 6f; 5:; li 31,0; 6:; lwz 9,0x4(31); lha 3,0xe8(9); lwz 0,0xec(9); add 3,31,3; mtspr 8,0; blrl; bl _s80112D40_2; mr. 30,3; beq 7f; lwz 9,0x0(30); lha 3,0x48(9); lwz 0,0x4c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 7f; lwz 9,0x0(30); lha 3,0xc8(9); lwz 0,0xcc(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 7f; lwz 9,0x0(30); lha 3,0x170(9); lwz 0,0x174(9); add 3,30,3; mtspr 8,0; blrl; cmpw 26,3; blt 7f; lwz 4,0x0(28); mr 5,31; addi 3,1,8; bl _s80112D40_3; mr 3,25; addi 4,1,8; bl _s80112D40_4; addi 3,1,8; li 4,2; bl _s80112D40_5; 7:; lwz 0,0x74(1); lwz 12,0x50(1); mtspr 8,0; lmw 25,0x54(1); mtcrf 8,12; addi 1,1,112"

extern "C" void _s80112D40_0();
extern "C" void _s80112D40_1();
extern "C" void _s80112D40_2();
extern "C" void _s80112D40_3();
extern "C" void _s80112D40_4();
extern "C" void _s80112D40_5();

struct ObjTestSim {
    void AppendInteractionsForAuto_InteractionList();
};

void ObjTestSim::AppendInteractionsForAuto_InteractionList() {
}
