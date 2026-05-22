// 0x801C93F4 MODTarget::GetVariable(char (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801C93F4_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801C93F4_1; mr 30,3; li 0,0; stb 0,0x0(30); mr 4,31; lwz 3,-30160(13); bl _s801C93F4_2; cmpwi 3,0; bne 1f; li 0,1; lis 11,-32705; stw 0,0x84(29); addi 10,11,-8792; mr 3,29; li 4,4; lwz 9,-8792(11); lhz 0,0x4(10); lbz 8,0x6(10); stw 9,0x0(30); sth 0,0x4(30); stb 8,0x6(30); bl _s801C93F4_3; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 1f; lis 4,-32705; lwz 6,0x94(29); addi 4,4,12552; addi 3,29,200; li 5,0; bl _s801C93F4_4; 1:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C93F4_0();
extern "C" void _s801C93F4_1();
extern "C" void _s801C93F4_2();
extern "C" void _s801C93F4_3();
extern "C" void _s801C93F4_4();
extern "C" void f_801C93F4() {}
