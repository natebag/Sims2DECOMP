// 0x8022732C IFFBehaviorTree::~IFFBehaviorTree(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 6,-32734; lis 8,-32704; lis 9,-32688; addi 3,3,-13400; addi 4,4,29548; addi 5,5,29588; addi 6,6,29620; addi 8,8,-7020; addi 9,9,-13440; li 7,0; bl _s8022732C_0; stw 3,-23812(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,184; bl _s8022732C_1; bl _s8022732C_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8022732C_0();
extern "C" void _s8022732C_1();
extern "C" void _s8022732C_2();
extern "C" void f_8022732C() {}
