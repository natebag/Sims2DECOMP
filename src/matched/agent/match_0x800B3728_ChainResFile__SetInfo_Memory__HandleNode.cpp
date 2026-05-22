// 0x800B3728 ChainResFile::SetInfo(Memory::HandleNode (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,3; mr 25,4; mr 26,5; mr 27,6; mr 28,7; li 4,0; li 30,0; bl _s800B3728_0; mr 3,29; li 4,-99; bl _s800B3728_1; addi 3,29,16; lwzx 0,3,30; cmpwi 0,0; beq 2f; mr 31,3; 0:; lwz 3,0x0(31); lwz 9,0xc(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwz 11,0x0(31); mr 5,26; mr 6,27; mr 7,28; lwz 9,0xc(11); mr 4,25; lha 3,0x118(9); lwz 0,0x11c(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,0x0(31); bl _s800B3728_2; mr 4,3; mr 3,29; bl _s800B3728_3; lwz 3,0x0(31); bl _s800B3728_4; cmpwi 3,0; beq 2f; 1:; addi 30,30,1; addi 31,31,24; cmpwi 30,7; bgt 2f; lwz 0,0x0(31); cmpwi 0,0; bne 0b; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800B3728_0();
extern "C" void _s800B3728_1();
extern "C" void _s800B3728_2();
extern "C" void _s800B3728_3();
extern "C" void _s800B3728_4();
extern "C" void f_800B3728() {}
