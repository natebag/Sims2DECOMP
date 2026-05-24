// 0x800DB16C cXObjectImpl::Cleanup(cXObject (1112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 28,3; cmpwi 4,0; bne 12f; lwz 3,0x4(28); li 4,3; lwz 9,0x4(3); lha 0,0x1d0(9); lwz 9,0x1d4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 9f; lwz 3,0x4(28); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 8f; cmpwi 28,0; beq 0f; lwz 9,0x4(28); li 4,3; lwz 3,0x0(9); bl _s800DB16C_0; mr 11,3; b 1f; 0:; li 11,0; 1:; cmpwi 11,0; beq 12f; lwz 9,0x4(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 2f; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 3f; 2:; li 31,0; 3:; cmpwi 31,0; beq 10f; 4:; lwz 11,0x0(31); li 4,3; lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x1d0(9); lwz 0,0x1d4(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; lwz 10,0x0(31); li 6,0; li 4,3; li 5,0; lwz 11,0x4(10); lwz 9,0x4(11); lwz 0,0x104(9); lha 3,0x100(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x0(31); li 5,0; li 4,62; addi 3,3,40; bl _s800DB16C_1; lwz 3,0x0(31); li 4,8; addi 3,3,40; bl _s800DB16C_2; lha 5,0x0(3); li 4,8; lwz 3,0x0(31); rlwinm 5,5,0,27,25; addi 3,3,40; bl _s800DB16C_3; lwz 10,0x4(28); lwz 9,0x0(31); lwz 11,0x4(10); lwz 29,0x0(9); lwz 0,0x37c(11); lha 3,0x378(11); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x4(28); mr 30,3; li 4,1; lwz 9,0x4(11); lha 3,0x1d0(9); lwz 0,0x1d4(9); add 3,11,3; mtspr 8,0; blrl; mr 5,3; mr 4,30; mr 3,29; bl _s800DB16C_4; 5:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 6f; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 7f; 6:; li 31,0; 7:; cmpwi 31,0; bne 4b; b 10f; 8:; lwz 11,0x4(28); li 6,0; li 4,3; li 5,0; lwz 9,0x4(11); addi 30,28,40; lwz 0,0x104(9); lha 3,0x100(9); mtspr 8,0; add 3,11,3; blrl; li 5,0; li 4,62; mr 3,30; bl _s800DB16C_5; li 4,8; mr 3,30; bl _s800DB16C_6; lha 5,0x0(3); li 4,8; mr 3,30; rlwinm 5,5,0,27,25; bl _s800DB16C_7; lwz 11,0x4(28); lwz 29,0x0(28); lwz 9,0x4(11); lwz 0,0x37c(9); lha 3,0x378(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(28); mr 30,3; li 4,1; lwz 9,0x4(11); lha 3,0x1d0(9); lwz 0,0x1d4(9); add 3,11,3; mtspr 8,0; blrl; mr 5,3; mr 4,30; mr 3,29; bl _s800DB16C_8; b 10f; 9:; lwz 11,0x4(28); addi 31,1,16; mr 4,31; addi 5,1,24; lwz 9,0x4(11); addi 6,1,28; addi 7,1,8; addi 8,1,32; lwz 0,0x1a4(9); lha 3,0x1a0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(28); lwz 9,0x4(11); lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(28); li 4,64; lwz 9,0x4(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 10f; lwz 9,0xec(28); li 4,1; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,28,3; blrl; lwz 0,0x20(1); cmpwi 0,0; beq 10f; lwz 3,0x4(28); mr 4,31; lwz 5,0x18(1); lwz 9,0x4(3); lwz 6,0x1c(1); lha 0,0x138(9); lwz 9,0x13c(9); add 3,3,0; lha 7,0x8(1); mtspr 8,9; blrl; 10:; lwz 10,0x4(28); lwz 30,0x58(28); lwz 9,0x4(10); lwz 11,0x0(30); lha 3,0x328(9); lwz 9,0x32c(9); addi 29,11,552; add 3,10,3; lha 0,0x228(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; li 5,-1; mtspr 8,0; blrl; lwz 3,-21492(13); cmpwi 3,0; beq 11f; lha 4,0x64(28); bl _s800DB16C_9; 11:; lwz 11,0x58(28); lwz 9,0x0(11); lwz 0,0x1ec(9); lha 3,0x1e8(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(28); cmpw 3,0; bne 12f; lwz 3,0x58(28); li 4,0; lwz 9,0x0(3); lha 0,0x1f0(9); lwz 9,0x1f4(9); add 3,3,0; mtspr 8,9; blrl; 12:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"

extern "C" void _s800DB16C_0();
extern "C" void _s800DB16C_1();
extern "C" void _s800DB16C_2();
extern "C" void _s800DB16C_3();
extern "C" void _s800DB16C_4();
extern "C" void _s800DB16C_5();
extern "C" void _s800DB16C_6();
extern "C" void _s800DB16C_7();
extern "C" void _s800DB16C_8();
extern "C" void _s800DB16C_9();

struct cXObjectImpl {
    void Cleanup_cXObject();
};

void cXObjectImpl::Cleanup_cXObject() {
}
