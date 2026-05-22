// 0x801CFA6C O2TTarget::OnQuitGameDialogClose(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,1; bne 0f; lis 3,-32705; addi 3,3,9192; bl _s801CFA6C_0; b 2f; 0:; cmpwi 4,0; bne 1f; lis 3,-32705; addi 3,3,-2020; bl _s801CFA6C_1; b 2f; 1:; lis 3,-32705; li 4,0; addi 3,3,15972; li 5,0; li 6,0; li 7,0; bl _s801CFA6C_2; li 0,0; stw 0,0x250(31); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801CFA6C_0();
extern "C" void _s801CFA6C_1();
extern "C" void _s801CFA6C_2();
extern "C" void f_801CFA6C() {}
