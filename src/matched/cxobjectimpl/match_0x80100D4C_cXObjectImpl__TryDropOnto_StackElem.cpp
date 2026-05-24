// 0x80100D4C cXObjectImpl::TryDropOnto(StackElem (572 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,5; mr 30,3; lha 0,0x0(31); mr 29,4; cmpwi 0,0; bne 0f; lha 27,0x2(31); b 3f; 0:; lha 9,0x2(31); cmpwi 9,0; blt 1f; lbz 0,0x7(29); cmpw 9,0; blt 2f; 1:; lwz 11,0x0(30); li 0,1; stw 0,-24512(13); li 9,8; sth 9,0x34(11); li 4,8; b 9f; 2:; mr 3,29; bl _s80100D4C_0; lha 0,0x2(31); add 0,0,0; lhax 27,3,0; 3:; lha 0,0x4(31); cmpwi 0,0; bne 4f; lha 28,0x6(31); b 7f; 4:; lha 9,0x6(31); cmpwi 9,0; blt 5f; lbz 0,0x7(29); cmpw 9,0; blt 6f; 5:; lwz 11,0x0(30); li 0,1; stw 0,-24512(13); li 9,8; sth 9,0x34(11); li 4,8; b 9f; 6:; mr 3,29; bl _s80100D4C_1; lha 0,0x6(31); add 0,0,0; lhax 28,3,0; 7:; lwz 3,0x4(30); mr 4,27; lwz 9,0x4(3); lha 0,0x2b8(9); lwz 9,0x2bc(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; bne 8f; lwz 11,0x0(30); li 0,1; stw 0,-24512(13); li 9,27; sth 9,0x34(11); li 4,27; b 9f; 8:; lwz 3,0x4(30); lha 4,0x4(29); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr. 29,3; bne 10f; lwz 11,0x0(30); li 0,1; stw 0,-24512(13); li 9,21; sth 9,0x34(11); li 4,21; 9:; lwz 11,0x4(30); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 13f; 10:; lha 4,0x4(31); cmpwi 4,0; beq 11f; lwz 11,0x4(30); addi 31,1,8; lwz 9,0x4(11); lwz 0,0x48c(9); lha 3,0x488(9); mtspr 8,0; add 3,11,3; blrl; li 0,-16; mr 30,3; stw 0,0x4(31); mr 4,31; stw 0,0x8(1); li 5,1; mr 6,29; mr 7,28; lwz 9,0x4(30); lha 3,0x130(9); lwz 0,0x134(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 12f; 11:; li 3,0; li 4,0; b 13f; 12:; lwz 9,0x4(30); mr 4,31; mr 6,29; mr 7,28; lha 3,0x138(9); li 5,1; lwz 0,0x13c(9); add 3,30,3; mtspr 8,0; blrl; li 3,0; li 4,1; 13:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s80100D4C_0();
extern "C" void _s80100D4C_1();

struct cXObjectImpl {
    void TryDropOnto_StackElem();
};

void cXObjectImpl::TryDropOnto_StackElem() {
}
