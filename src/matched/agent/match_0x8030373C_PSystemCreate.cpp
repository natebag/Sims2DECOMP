// 0x8030373C PSystemCreate (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; lwz 3,-22692(13); bl _s8030373C_0; mr. 31,3; li 3,-1; beq 0f; lis 5,-32720; mr 4,30; addi 5,5,13568; mr 3,31; bl _s8030373C_1; stw 31,0x0(29); li 3,0; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8030373C_0();
extern "C" void _s8030373C_1();
extern "C" void f_8030373C() {}
