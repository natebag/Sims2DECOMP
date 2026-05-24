// 0x8010958C cXObjectImpl::TryAnimate(StackElem (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,5; li 0,0; lbz 11,0x3(30); mr 29,4; stw 0,0x8(1); li 9,0; cmpwi 11,0; beq 0f; addi 9,11,3; b 2f; 0:; lbz 0,0x5(30); andi. 11,0,1; beq 1f; li 9,1; 1:; andi. 11,0,16; beq 2f; ori 9,9,2; 2:; cmpwi 9,7; bne 3f; lwz 31,0x4(3); b 5f; 3:; cmpwi 9,8; beq 4f; lwz 11,0x0(3); li 0,1; stw 0,-24512(13); li 9,5; sth 9,0x34(11); li 4,5; lwz 11,0x4(3); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 7f; 4:; lwz 3,-21484(13); lha 4,0x4(29); lwz 9,0x0(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; mr 31,3; 5:; mr 4,29; mr 5,30; mr 3,31; addi 6,1,8; bl _s8010958C_0; mr 29,3; mr 30,4; cmpwi 31,0; beq 6f; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x198(9); lwz 9,0x19c(9); add 3,3,0; mtspr 8,9; blrl; lwz 5,0x8(1); mr 4,31; bl _s8010958C_1; 6:; mr 3,29; mr 4,30; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s8010958C_0();
extern "C" void _s8010958C_1();

struct cXObjectImpl {
    void TryAnimate_StackElem();
};

void cXObjectImpl::TryAnimate_StackElem() {
}
