// 0x801065B0 cXObjectImpl::TryAnimateObject(StackElem (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lwz 9,0x0(5); lwz 10,0x4(5); mr 30,3; mr 29,4; stw 9,0x10(1); stw 10,0x14(1); lbz 0,0x10(1); andi. 9,0,1; beq 0f; lwz 3,0x4(30); lha 4,0x4(29); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; bne 1f; b 3f; 0:; lwz 31,0x4(30); 1:; lha 4,0x12(1); mr 3,30; lha 5,0x14(1); li 6,0; li 7,0; addi 8,1,8; bl _s801065B0_0; addi 0,1,16; cmpwi 3,-1; mr 28,0; bne 2f; cmpwi 4,-1; beq 4f; 2:; lwz 11,0x0(31); lwz 9,0x18(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; lis 4,-32688; addi 4,4,-18488; bl _s801065B0_1; mr. 31,3; bne 5f; 3:; lwz 11,0x0(30); li 0,1; stw 0,-24512(13); li 9,21; sth 9,0x34(11); li 4,21; lwz 11,0x4(30); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; 4:; li 3,-1; li 4,-1; b 12f; 5:; lbz 0,0x10(1); andi. 9,0,4; beq 9f; andi. 9,0,8; beq 7f; lbz 0,0x6(28); cmpwi 0,0; beq 6f; lwz 3,0x4(30); extsb 4,0; lwz 9,0x4(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; b 8f; 6:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; b 8f; 7:; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; 8:; lha 4,0x8(1); mr 3,31; bl _s801065B0_2; b 12f; 9:; andi. 9,0,2; beq 10f; lha 4,0x8(1); mr 3,31; li 5,0; b 11f; 10:; lha 30,0x8(1); mr 3,29; bl _s801065B0_3; lbz 0,0x1(28); mr 4,30; add 0,0,0; add 5,3,0; mr 3,31; 11:; bl _s801065B0_4; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"

extern "C" void _s801065B0_0();
extern "C" void _s801065B0_1();
extern "C" void _s801065B0_2();
extern "C" void _s801065B0_3();
extern "C" void _s801065B0_4();

struct cXObjectImpl {
    void TryAnimateObject_StackElem();
};

void cXObjectImpl::TryAnimateObject_StackElem() {
}
