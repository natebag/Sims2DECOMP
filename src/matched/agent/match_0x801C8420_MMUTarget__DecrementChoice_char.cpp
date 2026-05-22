// 0x801C8420 MMUTarget::DecrementChoice(char (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-272(1); mfspr 0,8; stw 31,0x10c(1); stw 0,0x114(1); mr 31,3; lwz 0,0x8c(31); cmpwi 0,0; bne 5f; lwz 0,0xb0(31); cmpwi 0,1; bne 1f; lwz 5,0xa4(31); addic. 5,5,-1; bge 0f; li 5,1; 0:; lis 4,-32705; addi 3,1,8; addi 4,4,-8800; crxor 6,6,6; bl _s801C8420_0; lwz 9,0x80(31); lis 4,-32705; addi 4,4,10332; addi 5,1,8; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0xb0(31); cmpwi 0,0; bne 3f; lwz 5,0xb8(31); addic. 5,5,-1; bge 2f; li 5,2; 2:; lis 4,-32705; addi 3,1,8; addi 4,4,-8800; crxor 6,6,6; bl _s801C8420_1; lwz 9,0x80(31); lis 4,-32705; addi 4,4,10356; addi 5,1,8; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 3:; lwz 0,0xb0(31); cmpwi 0,4; bne 5f; lwz 5,0xc0(31); addic. 5,5,-1; bge 4f; li 5,1; 4:; lis 4,-32705; addi 3,1,8; addi 4,4,-8800; crxor 6,6,6; bl _s801C8420_2; lwz 9,0x80(31); lis 4,-32705; addi 4,4,10384; addi 5,1,8; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 5:; lwz 0,0x114(1); mtspr 8,0; lwz 31,0x10c(1); addi 1,1,272"
extern "C" void _s801C8420_0();
extern "C" void _s801C8420_1();
extern "C" void _s801C8420_2();
extern "C" void f_801C8420() {}
