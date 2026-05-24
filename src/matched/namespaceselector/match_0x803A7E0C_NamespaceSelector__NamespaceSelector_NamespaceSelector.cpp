// 0x803A7E0C NamespaceSelector::NamespaceSelector(NamespaceSelector (916 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-232(1); mfspr 0,8; stmw 21,0xbc(1); stw 0,0xec(1); mr 24,4; mr 25,3; lwz 0,0x0(24); li 9,0; addi 30,25,8; li 3,20; stw 0,0x0(25); addi 29,24,8; lwz 0,0x4(24); stw 0,0x4(25); stw 9,0x4(30); bl _s803A7E0C_0; stw 3,0x0(3); stw 3,0x4(3); stw 3,0x4(30); lwz 11,0x0(3); stw 11,0x18(1); lwz 9,0x4(29); lwz 0,0x0(9); mr 27,9; stw 11,0x20(1); b 2f; 0:; lwz 0,0x20(1); li 3,20; addi 28,29,8; stw 0,0x30(1); bl _s803A7E0C_1; lhz 0,0x8(29); mr 30,3; addi 31,30,8; sth 0,0x8(30); lwz 11,0xc(29); stw 11,0xc(30); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x8(28); stw 0,0x8(31); lwz 9,0x30(1); lwz 11,0x4(9); stw 9,0x0(30); stw 11,0x4(30); stw 30,0x0(11); stw 30,0x4(9); stw 30,0x28(1); lwz 9,0xa8(1); lwz 0,0x0(9); 2:; stw 0,0xa8(1); lwz 29,0xa8(1); li 0,1; cmpw 29,27; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; addi 30,25,16; li 3,20; stw 0,0x4(30); addi 29,24,16; bl _s803A7E0C_2; stw 3,0x0(3); stw 3,0x4(3); stw 3,0x4(30); lwz 11,0x0(3); stw 11,0x48(1); lwz 9,0x4(29); lwz 0,0x0(9); mr 22,9; stw 11,0x50(1); stw 0,0xac(1); addi 26,25,24; addi 21,24,24; addi 27,25,32; addi 23,24,32; b 6f; 4:; lwz 0,0x50(1); li 3,20; addi 28,29,8; stw 0,0x60(1); bl _s803A7E0C_3; lhz 0,0x8(29); mr 30,3; addi 31,30,8; sth 0,0x8(30); lwz 11,0xc(29); stw 11,0xc(30); cmpwi 11,0; beq 5f; lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 5:; lwz 0,0x8(28); stw 0,0x8(31); lwz 9,0x60(1); lwz 11,0x4(9); stw 9,0x0(30); stw 11,0x4(30); stw 30,0x0(11); stw 30,0x4(9); stw 30,0x58(1); lwz 9,0xac(1); lwz 0,0x0(9); stw 0,0xac(1); 6:; lwz 29,0xac(1); li 0,1; cmpw 29,22; bne 7f; li 0,0; 7:; cmpwi 0,0; bne 4b; stw 0,0x4(26); li 3,20; bl _s803A7E0C_4; stw 3,0x0(3); stw 3,0x4(3); stw 3,0x4(26); lwz 11,0x0(3); lwz 9,0x4(21); stw 11,0x78(1); mr 26,9; lwz 0,0x0(9); stw 11,0x80(1); b 10f; 8:; lwz 0,0x80(1); li 3,20; addi 28,29,8; stw 0,0x90(1); bl _s803A7E0C_5; lhz 0,0x8(29); mr 30,3; addi 31,30,8; sth 0,0x8(30); lwz 11,0xc(29); stw 11,0xc(30); cmpwi 11,0; beq 9f; lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 9:; lwz 0,0x8(28); stw 0,0x8(31); lwz 9,0x90(1); lwz 11,0x4(9); stw 9,0x0(30); stw 11,0x4(30); stw 30,0x0(11); stw 30,0x4(9); stw 30,0x88(1); lwz 9,0xb0(1); lwz 0,0x0(9); 10:; stw 0,0xb0(1); lwz 29,0xb0(1); li 31,1; cmpw 29,26; bne 11f; li 31,0; 11:; cmpwi 31,0; bne 8b; li 30,0; li 3,24; stw 30,0x4(27); bl _s803A7E0C_6; stw 30,0x8(27); stw 3,0x4(27); lbz 0,0xc(23); stb 0,0xc(27); lwz 9,0x4(23); lwz 0,0x4(9); cmpwi 0,0; bne 12f; stw 30,0x0(3); lwz 9,0x4(27); stw 30,0x4(9); lwz 11,0x4(27); stw 11,0x8(11); lwz 9,0x4(27); stw 9,0xc(9); b 17f; 12:; stw 31,0x0(3); mr 3,27; lwz 9,0x4(23); lwz 30,0x4(27); lwz 4,0x4(9); mr 5,30; bl _s803A7E0C_7; stw 3,0x4(30); lwz 9,0x4(27); addi 11,9,8; lwz 9,0x4(9); b 14f; 13:; lwz 9,0x8(9); 14:; lwz 0,0x8(9); cmpwi 0,0; bne 13b; stw 9,0x0(11); lwz 9,0x4(27); addi 11,9,12; lwz 9,0x4(9); b 16f; 15:; lwz 9,0xc(9); 16:; lwz 0,0xc(9); cmpwi 0,0; bne 15b; stw 9,0x0(11); 17:; lwz 9,0x8(23); mr 3,25; stw 9,0x8(27); lwz 0,0x30(24); stw 0,0x30(25); lwz 0,0xec(1); mtspr 8,0; lmw 21,0xbc(1); addi 1,1,232"

extern "C" void _s803A7E0C_0();
extern "C" void _s803A7E0C_1();
extern "C" void _s803A7E0C_2();
extern "C" void _s803A7E0C_3();
extern "C" void _s803A7E0C_4();
extern "C" void _s803A7E0C_5();
extern "C" void _s803A7E0C_6();
extern "C" void _s803A7E0C_7();

struct NamespaceSelector {
    void NamespaceSelector_NamespaceSelector();
};

void NamespaceSelector::NamespaceSelector_NamespaceSelector() {
}
