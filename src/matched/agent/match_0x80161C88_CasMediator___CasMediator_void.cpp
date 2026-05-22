// 0x80161C88 CasMediator::~CasMediator(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s80161C88_0; lwz 0,0x8(31); cmpwi 0,0; beq 0f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s80161C88_1; lwz 9,0x4(31); li 0,0; stw 9,0x8(9); lwz 11,0x4(31); stw 0,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 0,0x8(31); 0:; lwz 3,0x4(31); cmpwi 3,0; beq 1f; li 4,20; bl _s80161C88_2; 1:; andi. 0,30,1; beq 2f; mr 3,31; bl _s80161C88_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80161C88_0();
extern "C" void _s80161C88_1();
extern "C" void _s80161C88_2();
extern "C" void _s80161C88_3();
extern "C" void f_80161C88() {}
