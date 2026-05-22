// 0x80089C10 EGameStateMan::DeleteAllStates(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 3,0x0(31); cmpwi 3,0; beq 0f; lwz 3,0x0(3); li 4,0; lwz 9,0x8(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; 0:; li 0,0; addi 30,31,4; stw 0,0x0(31); lwz 9,0x4(30); b 3f; 1:; lwz 0,0x8(30); lwz 11,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 2f; cmpwi 11,0; beq 2f; lwz 9,0x8(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr 9,31; 3:; li 0,1; cmpwi 9,0; bne 4f; li 0,0; 4:; cmpwi 0,0; bne 1b; mr 3,30; bl _s80089C10_0; lis 3,-32697; addi 3,3,24012; bl _s80089C10_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80089C10_0();
extern "C" void _s80089C10_1();
extern "C" void f_80089C10() {}
