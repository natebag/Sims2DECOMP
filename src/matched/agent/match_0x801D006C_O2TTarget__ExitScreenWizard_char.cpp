// 0x801D006C O2TTarget::ExitScreenWizard(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x0(3); lis 9,-32705; addi 4,9,14728; cmpwi 0,0; beq 0f; lwz 0,0x1c(3); cmpwi 0,0; beq 0f; lwz 6,0x7c(3); lis 5,-24685; mr 3,0; ori 5,5,65396; li 7,0; bl _s801D006C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801D006C_0();
extern "C" void f_801D006C() {}
