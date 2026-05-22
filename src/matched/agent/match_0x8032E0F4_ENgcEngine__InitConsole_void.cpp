// 0x8032E0F4 ENgcEngine::InitConsole(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-26408(13); cmpwi 0,0; beq 1f; li 0,0; lis 30,-32692; stw 0,-26408(13); bl _s8032E0F4_0; lis 29,-32702; bl _s8032E0F4_1; lis 31,-32692; bl _s8032E0F4_2; addi 3,30,18432; lwz 8,-26492(13); lis 4,-32717; lis 6,-32692; li 7,4096; li 9,1; mr 5,3; addi 4,4,-5228; addi 6,6,23328; bl _s8032E0F4_3; addi 3,30,18432; bl _s8032E0F4_4; 0:; addi 3,29,5796; addi 4,31,28224; bl _s8032E0F4_5; cmpwi 3,0; beq 0b; 1:; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8032E0F4_0();
extern "C" void _s8032E0F4_1();
extern "C" void _s8032E0F4_2();
extern "C" void _s8032E0F4_3();
extern "C" void _s8032E0F4_4();
extern "C" void _s8032E0F4_5();
extern "C" void f_8032E0F4() {}
