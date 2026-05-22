// 0x800ACC98 IFFBehavior::CountTrees(short) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,2; li 0,-1; beq 2f; bgt 0f; cmpwi 4,1; beq 1f; b 5f; 0:; cmpwi 4,3; beq 3f; b 5f; 1:; bl _s800ACC98_0; b 4f; 2:; bl _s800ACC98_1; b 4f; 3:; bl _s800ACC98_2; 4:; mr 0,3; 5:; cmpwi 0,-1; beq 6f; lwz 11,-21508(13); mr 4,0; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xc(3); lis 4,16968; ori 4,4,16726; lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; b 7f; 6:; li 3,0; 7:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800ACC98_0();
extern "C" void _s800ACC98_1();
extern "C" void _s800ACC98_2();
extern "C" void f_800ACC98() {}
