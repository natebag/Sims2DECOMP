// 0x8016F50C CasSimRenderer::CheckPending(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 4,0x204(31); cmpwi 4,0; beq 1f; lis 29,-32693; addi 3,29,11064; bl _s8016F50C_0; cmpwi 3,0; bne 0f; li 3,1; b 2f; 0:; lis 9,-32706; lwz 5,0x204(31); lfs f1,0x1750(9); addi 30,31,372; li 6,-1; li 7,0; li 4,1; mr 3,30; bl _s8016F50C_1; mr 3,30; li 4,1; bl _s8016F50C_2; lwz 4,0x204(31); addi 3,29,11064; li 5,1; bl _s8016F50C_3; li 0,0; stw 0,0x204(31); 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8016F50C_0();
extern "C" void _s8016F50C_1();
extern "C" void _s8016F50C_2();
extern "C" void _s8016F50C_3();
extern "C" void f_8016F50C() {}
