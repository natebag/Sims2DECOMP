// 0x8008DB5C LiveModeChangeHouseStateMachine::Reset(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32707; lis 11,-32697; lfs f1,0x7de4(9); li 0,0; stw 0,0x5c14(11); li 4,0; bl _s8008DB5C_0; li 30,2; lis 9,-32697; addi 9,9,24012; addi 31,9,280; 0:; lwz 0,0x0(31); addi 31,31,4; mr 3,0; cmpwi 0,0; beq 1f; bl _s8008DB5C_1; 1:; addic. 30,30,-1; bne 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8008DB5C_0();
extern "C" void _s8008DB5C_1();
extern "C" void f_8008DB5C() {}
