// 0x800ACD44 IFFBehavior::GetTreeByIndex(int, (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,4; mr 30,3; cmpwi 5,2; mr 28,6; li 4,-1; beq 2f; bgt 0f; cmpwi 5,1; beq 1f; b 5f; 0:; cmpwi 5,3; beq 3f; b 5f; 1:; mr 3,30; bl _s800ACD44_0; b 4f; 2:; mr 3,30; bl _s800ACD44_1; b 4f; 3:; mr 3,30; bl _s800ACD44_2; 4:; mr 4,3; 5:; cmpwi 4,-1; li 3,0; beq 7f; lwz 3,-21508(13); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 6f; lwz 9,0xc(31); lis 4,16968; extsh 5,29; ori 4,4,16726; lha 3,0x90(9); li 6,0; lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 6f; lwz 9,0xc(31); mr 4,3; addi 5,1,8; li 0,0; lha 3,0xb0(9); lwz 9,0xb4(9); add 3,31,3; sth 0,0x8(1); mtspr 8,9; blrl; lha 4,0x8(1); mr 3,30; mr 5,28; li 6,1; bl _s800ACD44_3; b 7f; 6:; li 3,0; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800ACD44_0();
extern "C" void _s800ACD44_1();
extern "C" void _s800ACD44_2();
extern "C" void _s800ACD44_3();
extern "C" void f_800ACD44() {}
