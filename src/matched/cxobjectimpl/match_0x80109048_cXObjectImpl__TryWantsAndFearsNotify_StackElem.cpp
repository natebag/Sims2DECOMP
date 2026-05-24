// 0x80109048 cXObjectImpl::TryWantsAndFearsNotify(StackElem (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 30,5; lis 9,-32697; lha 28,0x0(30); mr 31,3; li 0,0; mr 27,4; lwz 3,0x5eec(9); rlwinm 4,28,0,16,31; sth 0,0xe(1); sth 0,0xc(1); bl _s80109048_0; mr. 29,3; bne 0f; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,89; sth 9,0x34(11); li 4,89; b 10f; 0:; lbz 0,0xa(29); cmpwi 0,0; beq 1f; lbz 4,0x2(30); mr 3,31; addi 5,1,8; addi 6,1,10; extsb 4,4; bl _s80109048_1; lha 4,0x8(1); mr 3,31; lha 5,0xa(1); li 6,0; li 7,0; addi 8,1,12; bl _s80109048_2; 1:; lbz 0,0xb(29); cmpwi 0,0; beq 2f; lbz 4,0x3(30); mr 3,31; addi 5,1,8; addi 6,1,10; extsb 4,4; bl _s80109048_3; lha 4,0x8(1); mr 3,31; lha 5,0xa(1); li 6,0; li 7,0; addi 8,1,14; bl _s80109048_4; 2:; lha 11,0x4(27); addi 30,1,16; lhz 9,0xc(1); lhz 0,0xe(1); cmpwi 11,-2; sth 28,0x10(1); sth 9,0x12(1); sth 0,0x14(1); beq 5f; bgt 3f; cmpwi 11,-3; beq 4f; b 8f; 3:; cmpwi 11,-1; beq 6f; cmpwi 11,0; beq 9f; b 8f; 4:; lwz 3,-21476(13); mr 4,30; li 5,0; lwz 9,0x0(3); lha 0,0x1a0(9); lwz 9,0x1a4(9); b 7f; 5:; lwz 3,-21476(13); mr 4,30; li 5,0; lwz 9,0x0(3); lha 0,0x1a8(9); lwz 9,0x1ac(9); b 7f; 6:; lwz 3,-21476(13); mr 4,30; li 5,0; lwz 9,0x0(3); lha 0,0x198(9); lwz 9,0x19c(9); 7:; add 3,3,0; mtspr 8,9; blrl; b 12f; 8:; lwz 3,-21476(13); lha 4,0x4(27); lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; bne 11f; 9:; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,56; sth 9,0x34(11); li 4,56; 10:; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 13f; 11:; mr 4,30; li 5,1; bl _s80109048_5; 12:; sth 3,0x24(31); li 3,0; li 4,1; 13:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s80109048_0();
extern "C" void _s80109048_1();
extern "C" void _s80109048_2();
extern "C" void _s80109048_3();
extern "C" void _s80109048_4();
extern "C" void _s80109048_5();

struct cXObjectImpl {
    void TryWantsAndFearsNotify_StackElem();
};

void cXObjectImpl::TryWantsAndFearsNotify_StackElem() {
}
