// 0x8015B074 ResourceBehaviorTree::~ResourceBehaviorTree(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 0,0x8(31); addi 9,9,22600; mr 30,4; stw 9,0x0(31); cmpwi 0,0; beq 1f; lwz 3,0x60(31); cmpwi 3,0; beq 0f; bl _s8015B074_0; li 0,0; stw 0,0x60(31); 0:; li 0,0; stw 0,0x8(31); stw 0,0x60(31); 1:; mr 3,31; li 4,0; bl _s8015B074_1; andi. 0,30,1; beq 2f; mr 3,31; bl _s8015B074_2; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8015B074_0();
extern "C" void _s8015B074_1();
extern "C" void _s8015B074_2();
extern "C" void f_8015B074() {}
