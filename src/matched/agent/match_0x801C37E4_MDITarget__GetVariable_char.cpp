// 0x801C37E4 MDITarget::GetVariable(char (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801C37E4_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801C37E4_1; mr 30,3; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,9572; mr 4,31; bl _s801C37E4_2; cmpwi 3,0; bne 1f; li 0,1; lis 9,-32705; stw 0,0x90(29); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 4f; 1:; lis 3,-32705; mr 4,31; addi 3,3,9584; bl _s801C37E4_3; cmpwi 3,0; bne 2f; lis 4,-32705; mr 3,30; addi 4,4,-5236; li 5,468; crxor 6,6,6; bl _s801C37E4_4; b 4f; 2:; lis 3,-32705; mr 4,31; addi 3,3,9604; bl _s801C37E4_5; cmpwi 3,0; bne 3f; lis 4,-32705; lwz 5,0x8c(29); addi 4,4,-5236; mr 3,30; crxor 6,6,6; bl _s801C37E4_6; b 4f; 3:; lis 3,-32705; mr 4,31; addi 3,3,9624; bl _s801C37E4_7; cmpwi 3,0; bne 4f; lis 4,-32705; mr 3,30; addi 4,4,-5284; crxor 6,6,6; bl _s801C37E4_8; 4:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C37E4_0();
extern "C" void _s801C37E4_1();
extern "C" void _s801C37E4_2();
extern "C" void _s801C37E4_3();
extern "C" void _s801C37E4_4();
extern "C" void _s801C37E4_5();
extern "C" void _s801C37E4_6();
extern "C" void _s801C37E4_7();
extern "C" void _s801C37E4_8();
extern "C" void f_801C37E4() {}
