// 0x801527F4 XObjLang::~XObjLang(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; mr 11,3; addi 9,9,22024; stw 9,0x0(11); bl _s801527F4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801527F4_0();
extern "C" void f_801527F4() {}
