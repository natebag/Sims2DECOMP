// 0x80105420 cXObjectImpl::TryShowString(StackElem (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-296(1); mfspr 0,8; stmw 27,0x114(1); stw 0,0x12c(1); li 30,0; mr 31,3; stw 30,0x8(1); mr 28,4; mr 27,5; li 3,0; bl _s80105420_0; stw 30,0x8(1); bl _s80105420_1; mr 29,3; stw 29,0x8(1); lwz 30,0x0(29); lwz 3,0x10(28); lha 0,0xe8(30); addi 30,30,232; add 29,29,0; bl _s80105420_2; lwz 0,0x4(30); mr 4,3; mr 3,29; lha 5,0x0(27); mtspr 8,0; blrl; lwz 11,0x8(1); li 5,-1; lha 4,0x2(27); lwz 9,0x0(11); lha 3,0x80(9); lwz 0,0x84(9); add 3,11,3; mtspr 8,0; blrl; mr. 29,3; beq 0f; mr 3,29; bl _s80105420_3; cmpwi 3,0; beq 0f; lwz 11,0x4(31); addi 30,1,16; lwz 9,0x4(11); lha 3,0x510(9); lwz 0,0x514(9); add 3,11,3; mtspr 8,0; blrl; mr 5,3; lis 4,-32706; addi 4,4,-15956; mr 6,29; mr 3,30; crxor 6,6,6; bl _s80105420_4; mr 4,30; li 3,231; bl _s80105420_5; 0:; lwz 3,0x8(1); bl _s80105420_6; li 0,0; li 3,0; li 4,1; stw 0,0x8(1); lwz 0,0x12c(1); mtspr 8,0; lmw 27,0x114(1); addi 1,1,296"

extern "C" void _s80105420_0();
extern "C" void _s80105420_1();
extern "C" void _s80105420_2();
extern "C" void _s80105420_3();
extern "C" void _s80105420_4();
extern "C" void _s80105420_5();
extern "C" void _s80105420_6();

struct cXObjectImpl {
    void TryShowString_StackElem();
};

void cXObjectImpl::TryShowString_StackElem() {
}
