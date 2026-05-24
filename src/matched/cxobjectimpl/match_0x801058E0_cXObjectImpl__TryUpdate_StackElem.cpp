// 0x801058E0 cXObjectImpl::TryUpdate(StackElem (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,5; mr 30,3; lha 29,0x0(28); cmpwi 29,0; beq 0f; cmpwi 29,1; beq 1f; b 11f; 0:; lwz 31,0x4(30); b 2f; 1:; lwz 3,0x4(30); lha 4,0x4(4); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; bne 3f; lwz 0,-32048(13); cmpwi 0,0; bne 13f; lwz 9,0x0(30); li 0,21; stw 29,-24512(13); li 4,21; sth 0,0x34(9); b 12f; 2:; cmpwi 31,0; beq 11f; 3:; lha 5,0x2(28); cmpwi 5,2; beq 8f; bgt 4f; cmpwi 5,0; beq 13f; cmpwi 5,1; beq 5f; b 11f; 4:; cmpwi 5,3; beq 9f; cmpwi 5,4; beq 10f; b 11f; 5:; cmpwi 31,0; beq 6f; lwz 9,0x4(31); lha 3,0x520(9); lwz 0,0x524(9); add 3,31,3; mtspr 8,0; blrl; b 7f; 6:; li 3,0; 7:; lha 4,0x64(3); li 3,238; bl _s801058E0_0; b 13f; 8:; lwz 9,0x4(31); lwz 0,0x30c(9); lha 3,0x308(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; ori 0,0,65531; cmpw 3,0; beq 13f; bl _s801058E0_1; lwz 9,0x4(31); mr 30,3; lha 3,0x308(9); lwz 0,0x30c(9); add 3,31,3; mtspr 8,0; blrl; mr 4,3; mr 3,30; bl _s801058E0_2; b 13f; 9:; lwz 3,0x0(31); lwz 9,0x18(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 13f; lwz 9,0x320(3); addi 0,3,800; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; b 13f; 10:; lwz 11,-21424(13); cmpwi 11,0; beq 13f; lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; b 13f; 11:; lwz 11,0x0(30); li 0,1; stw 0,-24512(13); li 9,3; sth 9,0x34(11); li 4,3; 12:; lwz 11,0x4(30); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 14f; 13:; li 3,0; li 4,1; 14:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s801058E0_0();
extern "C" void _s801058E0_1();
extern "C" void _s801058E0_2();

struct cXObjectImpl {
    void TryUpdate_StackElem();
};

void cXObjectImpl::TryUpdate_StackElem() {
}
