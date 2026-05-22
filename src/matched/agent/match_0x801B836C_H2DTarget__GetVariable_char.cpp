// 0x801B836C H2DTarget::GetVariable(char (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; lbz 3,0x0(31); extsb 3,3; bl _s801B836C_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801B836C_1; mr 30,3; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,5116; mr 4,31; bl _s801B836C_2; cmpwi 3,0; bne 1f; lis 9,-32705; addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); 1:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801B836C_0();
extern "C" void _s801B836C_1();
extern "C" void _s801B836C_2();
extern "C" void f_801B836C() {}
