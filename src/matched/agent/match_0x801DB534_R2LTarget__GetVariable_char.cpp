// 0x801DB534 R2LTarget::GetVariable(char (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801DB534_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801DB534_1; mr 29,3; li 0,0; lis 3,-32705; stb 0,0x0(29); addi 3,3,19956; mr 4,31; bl _s801DB534_2; cmpwi 3,0; bne 1f; li 0,1; lis 9,-32705; stw 0,0x88(30); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(29); sth 0,0x4(29); stb 8,0x6(29); b 8f; 1:; lis 3,-32705; mr 4,31; addi 3,3,20020; bl _s801DB534_3; cmpwi 3,0; bne 2f; lwz 9,0xa0(30); cmpwi 9,0; blt 5f; lwz 0,0x9c(30); cmpw 9,0; bge 5f; b 4f; 2:; lis 3,-32705; mr 4,31; addi 3,3,19988; bl _s801DB534_4; cmpwi 3,0; bne 3f; mr 3,30; bl _s801DB534_5; cmpwi 3,0; bne 4f; b 5f; 3:; lis 3,-32705; mr 4,31; addi 3,3,20004; bl _s801DB534_6; cmpwi 3,0; bne 6f; mr 3,30; bl _s801DB534_7; cmpwi 3,0; beq 5f; 4:; lis 9,-32705; lhz 0,-5288(9); sth 0,0x0(29); b 8f; 5:; lis 9,-32705; lhz 0,-5284(9); sth 0,0x0(29); b 8f; 6:; lis 3,-32705; mr 4,31; addi 3,3,19968; bl _s801DB534_8; cmpwi 3,0; bne 8f; lwz 0,0x1cc(30); li 5,0; cmpwi 0,0; bne 7f; lwz 0,0xb8(30); subfic 9,0,0; adde 5,9,0; 7:; lis 4,-32705; mr 3,29; addi 4,4,-8800; crxor 6,6,6; bl _s801DB534_9; 8:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801DB534_0();
extern "C" void _s801DB534_1();
extern "C" void _s801DB534_2();
extern "C" void _s801DB534_3();
extern "C" void _s801DB534_4();
extern "C" void _s801DB534_5();
extern "C" void _s801DB534_6();
extern "C" void _s801DB534_7();
extern "C" void _s801DB534_8();
extern "C" void _s801DB534_9();
extern "C" void f_801DB534() {}
