// 0x8032528C EQuickdataManager::AllocateAndLoadResource(EFile (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 31,4; mr 26,5; lis 3,-32692; mr 30,6; li 4,28; li 5,8; addi 3,3,-20832; bl _s8032528C_0; bl _s8032528C_1; mr 28,3; stw 30,0x8(28); lwz 9,0x28(31); lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; mr 27,3; lis 3,-32702; addi 3,3,3612; bl _s8032528C_2; cmpw 30,3; li 0,0; bne 0f; li 0,1; 0:; stw 0,0xd24(29); lwz 5,0xd20(29); mr 3,28; mr 4,31; bl _s8032528C_3; li 0,0; add 4,27,26; stw 0,0xd24(29); li 5,0; lwz 9,0x28(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8032528C_0();
extern "C" void _s8032528C_1();
extern "C" void _s8032528C_2();
extern "C" void _s8032528C_3();
extern "C" void f_8032528C() {}
