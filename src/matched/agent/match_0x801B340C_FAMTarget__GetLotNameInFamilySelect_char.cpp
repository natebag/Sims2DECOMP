// 0x801B340C FAMTarget::GetLotNameInFamilySelect(char (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,4; mr 30,3; mr 3,31; bl _s801B340C_0; mr. 3,3; beq 4f; add 9,3,31; lbz 0,-1(9); addi 3,1,8; stb 0,0x8(1); bl _s801B340C_1; mr 4,3; mr 3,30; bl _s801B340C_2; mr. 29,3; bne 1f; b 4f; 0:; mr 4,31; mr 3,30; bl _s801B340C_3; mr 4,3; mr 3,30; bl _s801B340C_4; b 5f; 1:; li 31,0; 2:; mr 3,30; mr 4,31; bl _s801B340C_5; mr. 3,3; beq 3f; cmpw 3,29; beq 0b; 3:; addi 31,31,1; cmpwi 31,4; blt 2b; 4:; li 3,0; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s801B340C_0();
extern "C" void _s801B340C_1();
extern "C" void _s801B340C_2();
extern "C" void _s801B340C_3();
extern "C" void _s801B340C_4();
extern "C" void _s801B340C_5();
extern "C" void f_801B340C() {}
