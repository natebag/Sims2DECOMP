// 0x80109C30 cXObjectImpl::TryPlaySound(StackElem (448 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lbz 0,0x4(5); mr 31,4; lha 27,0x0(5); cmpwi 0,255; beq 0f; andi. 9,0,2; beq 0f; lha 28,0x4(31); b 1f; 0:; lha 28,0x64(3); 1:; lwz 3,0x10(31); bl _s80109C30_0; li 0,0; lwz 11,-21508(13); stw 0,0x8(1); mr 4,3; lwz 9,0x0(11); lwz 0,0x19c(9); lha 3,0x198(9); mtspr 8,0; add 3,11,3; blrl; mr 4,27; bl _s80109C30_1; lwz 0,0x8(1); mr 30,3; cmpw 30,0; beq 4f; cmpwi 30,0; beq 2f; lwz 9,0x0(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; 2:; lwz 11,0x8(1); cmpwi 11,0; beq 3f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 3:; stw 30,0x8(1); 4:; lwz 0,0x8(1); cmpwi 0,0; bne 7f; lwz 29,-21508(13); lwz 3,0x10(31); lwz 30,0x0(29); lha 0,0x198(30); addi 30,30,408; add 29,29,0; bl _s80109C30_2; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr 4,27; bl _s80109C30_3; lwz 0,0x8(1); mr 30,3; cmpw 30,0; beq 7f; cmpwi 30,0; beq 5f; lwz 9,0x0(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; 5:; lwz 11,0x8(1); cmpwi 11,0; beq 6f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 6:; stw 30,0x8(1); 7:; lwz 9,0x8(1); cmpwi 9,0; beq 8f; lwz 4,0x4c(9); mr 5,28; lwz 3,-21492(13); bl _s80109C30_4; lwz 11,0x8(1); cmpwi 11,0; beq 8f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 8:; li 3,0; li 4,1; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s80109C30_0();
extern "C" void _s80109C30_1();
extern "C" void _s80109C30_2();
extern "C" void _s80109C30_3();
extern "C" void _s80109C30_4();

struct cXObjectImpl {
    void TryPlaySound_StackElem();
};

void cXObjectImpl::TryPlaySound_StackElem() {
}
