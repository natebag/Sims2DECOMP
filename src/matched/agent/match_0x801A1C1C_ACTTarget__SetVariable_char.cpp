// 0x801A1C1C ACTTarget::SetVariable(char (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801A1C1C_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lis 3,-32705; mr 4,31; addi 3,3,-8816; li 5,14; bl _s801A1C1C_1; mr. 30,3; bne 1f; lis 4,-32705; addi 3,31,14; addi 4,4,-8800; stw 30,0x20(1); addi 5,1,32; crxor 6,6,6; bl _s801A1C1C_2; lwz 0,0x20(1); cmplwi 0,17; bgt 3f; mulli 11,0,76; addi 9,29,268; addi 10,29,244; stwx 30,9,11; lwzx 0,10,11; cmpwi 0,0; beq 3f; addi 9,29,240; stwx 30,9,11; stwx 30,10,11; b 3f; 1:; lis 3,-32705; mr 4,31; addi 3,3,-11032; bl _s801A1C1C_3; mr. 3,3; bne 2f; stw 3,0xd4(29); b 3f; 2:; lis 3,-32705; mr 4,31; addi 3,3,-10972; bl _s801A1C1C_4; mr. 31,3; bne 3f; stw 31,0xd4(29); addi 3,1,8; bl _s801A1C1C_5; lwz 6,0xdc(29); lis 4,-32705; addi 4,4,-8796; addi 3,1,8; li 5,0; bl _s801A1C1C_6; stw 31,0xd0(29); addi 3,1,8; li 4,2; bl _s801A1C1C_7; 3:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s801A1C1C_0();
extern "C" void _s801A1C1C_1();
extern "C" void _s801A1C1C_2();
extern "C" void _s801A1C1C_3();
extern "C" void _s801A1C1C_4();
extern "C" void _s801A1C1C_5();
extern "C" void _s801A1C1C_6();
extern "C" void _s801A1C1C_7();
extern "C" void f_801A1C1C() {}
