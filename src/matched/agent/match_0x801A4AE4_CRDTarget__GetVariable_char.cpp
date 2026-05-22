// 0x801A4AE4 CRDTarget::GetVariable(char (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801A4AE4_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,32; bl _s801A4AE4_1; mr 31,3; li 0,0; lis 3,-32705; stb 0,0x0(31); addi 3,3,-7904; mr 4,30; bl _s801A4AE4_2; cmpwi 3,0; bne 1f; li 0,1; lis 9,-32705; stw 0,0x84(29); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 3f; 1:; lis 3,-32705; mr 4,30; addi 3,3,-7892; bl _s801A4AE4_3; cmpwi 3,0; bne 2f; lis 4,-32705; lwz 5,0x9c(29); addi 4,4,-8800; mr 3,31; crxor 6,6,6; bl _s801A4AE4_4; b 3f; 2:; lis 3,-32705; mr 4,30; addi 3,3,-7872; bl _s801A4AE4_5; cmpwi 3,0; bne 3f; lis 4,-32705; mr 3,31; addi 4,4,-8800; li 5,0; crxor 6,6,6; bl _s801A4AE4_6; 3:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801A4AE4_0();
extern "C" void _s801A4AE4_1();
extern "C" void _s801A4AE4_2();
extern "C" void _s801A4AE4_3();
extern "C" void _s801A4AE4_4();
extern "C" void _s801A4AE4_5();
extern "C" void _s801A4AE4_6();
extern "C" void f_801A4AE4() {}
