// 0x801808D0 UIAUDIOTarget::SetVariable(char (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 29,0x8c(1); stw 0,0x9c(1); mr 31,4; mr 29,3; mr 30,5; mr 3,31; bl _s801808D0_0; mr. 3,3; beq 4f; cmpwi 31,0; beq 4f; cmpwi 30,0; beq 4f; li 0,0; li 11,0; stb 0,0x8(1); li 8,0; li 9,0; cmpw 11,3; bge 3f; addi 10,1,8; li 7,0; 0:; lbzx 0,31,11; cmpwi 0,58; bne 1f; addi 8,8,1; b 2f; 1:; cmpwi 8,1; bne 2f; stbx 0,10,9; addi 9,9,1; stbx 7,10,9; 2:; addi 11,11,1; cmpw 11,3; blt 0b; 3:; lwz 3,0x24(29); addi 4,1,8; bl _s801808D0_1; mr. 4,3; beq 4f; lwz 3,0x24(29); bl _s801808D0_2; 4:; lwz 0,0x9c(1); mtspr 8,0; lmw 29,0x8c(1); addi 1,1,152"
extern "C" void _s801808D0_0();
extern "C" void _s801808D0_1();
extern "C" void _s801808D0_2();
extern "C" void f_801808D0() {}
