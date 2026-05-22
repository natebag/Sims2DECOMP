// 0x801B0B78 FAMTarget::GetFamilyText(char (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-2368(1); mfspr 0,8; stmw 25,0x924(1); stw 0,0x944(1); mr 28,3; mr 31,4; mr 27,5; li 5,17; addi 3,1,8; bl _s801B0B78_0; li 25,0; lis 4,-32705; stb 25,0x19(1); addi 4,4,1464; addi 3,1,8; bl _s801B0B78_1; li 26,1; mr. 29,3; bne 0f; addi 30,1,264; addi 4,31,17; mr 3,30; li 5,2; bl _s801B0B78_2; li 26,0; stb 29,0x10a(1); b 1f; 0:; addi 30,1,264; addi 4,31,18; mr 3,30; li 5,2; bl _s801B0B78_3; stb 25,0x10a(1); 1:; mr 3,30; bl _s801B0B78_4; mr 4,3; mr 3,28; bl _s801B0B78_5; lwz 11,-21476(13); mr 4,3; lwz 9,0x0(11); lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 4,3; bne 4f; cmpwi 26,0; beq 3f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,1672; addi 3,1,2328; addi 31,1,280; crxor 6,6,6; bl _s801B0B78_6; lwz 9,0x918(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,31; bl _s801B0B78_7; mr 3,27; mr 4,31; bl _s801B0B78_8; b 6f; 3:; sth 4,0x0(27); b 6f; 4:; cmpwi 26,0; beq 5f; mr 3,28; mr 5,27; bl _s801B0B78_9; b 6f; 5:; mr 3,28; mr 5,27; bl _s801B0B78_10; 6:; lwz 0,0x944(1); mtspr 8,0; lmw 25,0x924(1); addi 1,1,2368"
extern "C" void _s801B0B78_0();
extern "C" void _s801B0B78_1();
extern "C" void _s801B0B78_2();
extern "C" void _s801B0B78_3();
extern "C" void _s801B0B78_4();
extern "C" void _s801B0B78_5();
extern "C" void _s801B0B78_6();
extern "C" void _s801B0B78_7();
extern "C" void _s801B0B78_8();
extern "C" void _s801B0B78_9();
extern "C" void _s801B0B78_10();
extern "C" void f_801B0B78() {}
