// 0x8029AFCC AptDisplayList::~AptDisplayList(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; li 4,0; bl _s8029AFCC_0; lwz 3,0x0(31); cmpwi 3,0; beq 0f; li 4,3; bl _s8029AFCC_1; 0:; andi. 0,30,1; beq 1f; mr 3,31; bl _s8029AFCC_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8029AFCC_0();
extern "C" void _s8029AFCC_1();
extern "C" void _s8029AFCC_2();
extern "C" void f_8029AFCC() {}
