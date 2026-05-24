// 0x801B209C cXObjectImpl::TryAnimateObject(StackElem (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_801B1884" lines="addi 3,31,244; bl _s801B209C_0; addi 29,1,2584; mr 4,28; mr 3,31; bl _s801B209C_1; mr 4,3; mr 5,30; mr 3,31; bl _s801B209C_2; lis 3,-32705; mr 4,30; addi 3,3,-8360; bl _s801B209C_3; lwz 4,0x16c(31); li 5,0; mr 3,31; bl _s801B209C_4; mr 4,3; mr 5,29; mr 3,31; bl _s801B209C_5; lis 3,-32705; mr 4,29; addi 3,3,1888; bl _s801B209C_6; lis 5,-32705; addi 4,26,24012; addi 5,5,1900; addi 3,1,3252; crxor 6,6,6; bl _s801B209C_7; lwz 9,0xcb4(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; addi 3,1,8; bl _s801B209C_8; cmpwi 31,0; addi 3,1,8; mfcr 30; bl _s801B209C_9; addi 4,1,8; addi 3,31,236; bl _s801B209C_10; lis 4,-32705; addi 3,31,240; addi 4,4,-8284; bl _s801B209C_11; lis 9,-32705; stw 27,0xd8(31); addi 9,9,1776; lis 10,-32709; lwz 11,0x0(9); lwz 12,0x4(9); addi 4,1,3256; addi 29,10,28880; mtcrf 128,30; stw 11,0xcb8(1); stw 12,0xcbc(1); stw 27,0xe4(31); stw 31,0x810(1); beq 1f; addi 3,1,2056; li 5,8; bl _s801B209C_12; b 2f; 1:; stw 31,0x808(1); 2:; lis 9,-32705; stw 29,0x814(1); addi 9,9,1744; addi 11,1,2056; lwz 4,0x808(1); addi 8,31,276; lwz 6,0x0(9); lwz 7,0x4(9); lis 10,-32709; lwz 5,0x4(11); mr 28,11; lwz 9,0x8(11); addi 29,10,28640; lwz 0,0xc(11); mtcrf 128,30; stw 4,0x114(31); addi 11,1,3264; stw 0,0xc(8); stw 5,0x4(8); stw 9,0x8(8); stw 6,0xcc0(1); stw 7,0xcc4(1); stw 31,0x810(1); beq 3f; mr 4,11; mr 3,28; li 5,8; bl _s801B209C_13; b 4f; 3:; stw 31,0x808(1); 4:; stw 29,0x814(1); lis 9,-32705; lwz 6,0x808(1); addi 9,9,-1960; lwz 5,0x4(28); addi 11,31,292; lwz 4,0x8(28); addi 0,31,196; lwz 10,0xc(28); mr 30,0; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 0,0; stw 6,0x124(31); lis 9,-32709; stw 10,0xc(11); addi 29,9,14552; stw 5,0x4(11); addi 9,1,3272; stw 4,0x8(11); stw 7,0xcc8(1); stw 8,0xccc(1)"

extern "C" void _s801B209C_0();
extern "C" void _s801B209C_1();
extern "C" void _s801B209C_2();
extern "C" void _s801B209C_3();
extern "C" void _s801B209C_4();
extern "C" void _s801B209C_5();
extern "C" void _s801B209C_6();
extern "C" void _s801B209C_7();
extern "C" void _s801B209C_8();
extern "C" void _s801B209C_9();
extern "C" void _s801B209C_10();
extern "C" void _s801B209C_11();
extern "C" void _s801B209C_12();
extern "C" void _s801B209C_13();

struct cXObjectImpl {
    void TryAnimateObject_StackElem();
};

void cXObjectImpl::TryAnimateObject_StackElem() {
}
