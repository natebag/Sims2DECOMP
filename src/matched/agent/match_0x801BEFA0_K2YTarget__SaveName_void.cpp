// 0x801BEFA0 K2YTarget::SaveName(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 3,-32705; li 30,0; addi 3,3,3292; li 31,0; bl _s801BEFA0_0; mr. 29,3; beq 0f; cmpwi 29,1; beq 1f; b 3f; 0:; lis 3,-32705; addi 3,3,5044; bl _s801BEFA0_1; mr 30,3; lis 3,-32705; addi 3,3,5064; b 2f; 1:; lis 3,-32705; addi 3,3,5080; bl _s801BEFA0_2; mr 30,3; lis 3,-32705; addi 3,3,5100; 2:; bl _s801BEFA0_3; mr 31,3; 3:; cmplwi 29,1; bgt 4f; lis 3,-32688; mr 4,30; li 5,32; addi 3,3,-16156; bl _s801BEFA0_4; lis 3,-32688; mr 4,31; addi 3,3,-16092; li 5,32; bl _s801BEFA0_5; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801BEFA0_0();
extern "C" void _s801BEFA0_1();
extern "C" void _s801BEFA0_2();
extern "C" void _s801BEFA0_3();
extern "C" void _s801BEFA0_4();
extern "C" void _s801BEFA0_5();
extern "C" void f_801BEFA0() {}
