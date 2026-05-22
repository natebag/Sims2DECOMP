// 0x8027085C AptActionInterpreter::CleanupAfterExecution(void (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 3,0x54(31); li 0,1; cmpwi 3,0; bne 0f; li 0,0; 0:; cmpwi 0,0; beq 1f; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s8027085C_0; lwz 11,0x54(31); lis 4,-32704; lis 5,-32704; addi 4,4,5040; lwz 9,0x8(11); addi 5,5,4952; li 6,663; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 4,0x8(1); li 0,0; stw 0,0x54(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8027085C_1; 1:; mr 3,30; bl _s8027085C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8027085C_0();
extern "C" void _s8027085C_1();
extern "C" void _s8027085C_2();
extern "C" void f_8027085C() {}
