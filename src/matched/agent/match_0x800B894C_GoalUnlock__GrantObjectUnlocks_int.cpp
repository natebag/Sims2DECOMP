// 0x800B894C GoalUnlock::GrantObjectUnlocks(int) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 0,20971; srawi 11,4,31; ori 0,0,34079; lis 9,-32696; mulhw 4,4,0; addi 27,9,24188; mr 31,3; li 29,-1; li 30,0; srawi 4,4,5; subf 4,11,4; extsh 28,4; b 2f; 0:; rlwinm 9,30,3,0,28; add 9,9,27; lha 0,0x4(9); cmpwi 0,0; beq 1f; cmpw 28,0; blt 1f; lwz 9,0x0(31); li 4,5; mr 5,30; lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 9,0x0(31); mr 29,30; li 4,5; mr 5,29; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 1:; addi 0,30,1; extsh 30,0; 2:; lwz 9,0x0(31); li 4,5; lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; cmpw 30,3; blt 0b; lwz 3,-26824(13); bl _s800B894C_0; cmpwi 3,0; beq 3f; cmpwi 29,-1; beq 3f; lis 9,-32697; lwz 3,0x5bcc(9); cmpwi 3,0; beq 3f; mr 5,29; li 4,5; bl _s800B894C_1; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800B894C_0();
extern "C" void _s800B894C_1();
extern "C" void f_800B894C() {}
