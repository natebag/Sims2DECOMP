// 0x8029DFA4 AptAnimationPoolData::HandleAutoNav(AptCIH (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 31,4; mr. 28,5; ble 9f; cmpwi 28,2; ble 0f; cmpwi 28,15; bgt 9f; cmpwi 28,14; blt 9f; 0:; lwz 0,0x68(30); cmpwi 0,0; bne 9f; cmpwi 6,0; bne 9f; mr 3,30; bl _s8029DFA4_0; lwz 5,0x64(30); cmpwi 5,0; beq 9f; cmpwi 31,0; bne 1f; lwz 4,0x48(5); mr 3,28; b 6f; 1:; mr 3,31; li 27,0; bl _s8029DFA4_1; li 29,0; cmpwi 3,13; bne 2f; mr 3,31; bl _s8029DFA4_2; subfic 0,3,0; adde 29,0,3; 2:; cmpwi 29,0; bne 4f; mr 3,31; li 29,0; bl _s8029DFA4_3; cmpwi 3,18; bne 3f; mr 3,31; bl _s8029DFA4_4; subfic 0,3,0; adde 29,0,3; 3:; cmpwi 29,0; beq 5f; 4:; li 27,1; 5:; cmpwi 27,0; beq 7f; mr 4,31; mr 3,28; li 5,0; 6:; bl _s8029DFA4_5; mr 31,3; 7:; cmpwi 31,0; beq 9f; lwz 3,0x64(30); li 4,1; bl _s8029DFA4_6; mr 3,31; li 4,2; bl _s8029DFA4_7; lwz 4,0x64(30); mr 3,30; li 5,2; bl _s8029DFA4_8; mr 3,30; mr 4,31; li 5,1; bl _s8029DFA4_9; lwz 11,0x64(30); cmpwi 11,0; beq 8f; lwz 9,0x8(11); lis 4,-32703; lis 5,-32703; addi 4,4,-30008; lha 3,0x10(9); addi 5,5,-30280; lwz 0,0x14(9); li 6,1387; add 3,11,3; mtspr 8,0; blrl; 8:; stw 31,0x64(30); lis 4,-32703; lis 5,-32703; addi 4,4,-30008; lwz 9,0x8(31); addi 5,5,-30280; li 6,1389; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8029DFA4_0();
extern "C" void _s8029DFA4_1();
extern "C" void _s8029DFA4_2();
extern "C" void _s8029DFA4_3();
extern "C" void _s8029DFA4_4();
extern "C" void _s8029DFA4_5();
extern "C" void _s8029DFA4_6();
extern "C" void _s8029DFA4_7();
extern "C" void _s8029DFA4_8();
extern "C" void _s8029DFA4_9();
extern "C" void f_8029DFA4() {}
