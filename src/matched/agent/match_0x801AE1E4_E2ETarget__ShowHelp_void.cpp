// 0x801AE1E4 E2ETarget::ShowHelp(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 5,-32705; addi 3,3,500; addi 5,5,-1380; li 4,0; li 6,0; li 7,1; li 8,0; bl _s801AE1E4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801AE1E4_0();
extern "C" void f_801AE1E4() {}
