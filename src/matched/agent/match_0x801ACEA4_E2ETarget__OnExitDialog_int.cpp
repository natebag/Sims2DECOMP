// 0x801ACEA4 E2ETarget::OnExitDialog(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s801ACEA4_0; cmpwi 3,0; bne 0f; lis 3,-32705; li 4,0; addi 3,3,-1952; li 5,0; li 6,0; li 7,0; bl _s801ACEA4_1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801ACEA4_0();
extern "C" void _s801ACEA4_1();
extern "C" void f_801ACEA4() {}
