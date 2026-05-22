// 0x801950C4 CASTarget::DontSaveNameEnterCBA(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32705; addi 3,3,-16192; bl _s801950C4_0; mr. 3,3; beq 0f; cmpwi 3,1; beq 1f; b 2f; 0:; lis 4,-32688; lis 3,-32705; addi 4,4,-16156; addi 3,3,-16164; bl _s801950C4_1; lis 4,-32688; lis 3,-32705; addi 3,3,-16116; addi 4,4,-16092; bl _s801950C4_2; b 2f; 1:; lis 4,-32688; lis 3,-32705; addi 4,4,-16156; addi 3,3,-16072; bl _s801950C4_3; lis 4,-32688; lis 3,-32705; addi 3,3,-16024; addi 4,4,-16092; bl _s801950C4_4; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801950C4_0();
extern "C" void _s801950C4_1();
extern "C" void _s801950C4_2();
extern "C" void _s801950C4_3();
extern "C" void _s801950C4_4();
extern "C" void f_801950C4() {}
