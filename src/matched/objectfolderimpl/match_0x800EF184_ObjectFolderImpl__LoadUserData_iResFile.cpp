// 0x800EF184 ObjectFolderImpl::LoadUserData(iResFile (604 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-360(1); mfspr 0,8; stmw 22,0x140(1); stw 0,0x16c(1); mr 25,3; mr 26,4; addi 3,1,12; mr 22,3; bl _s800EF184_0; lwz 9,0xc(26); lis 4,21875; ori 4,4,25970; lwz 0,0x7c(9); lha 3,0x78(9); mtspr 8,0; add 3,26,3; blrl; mr 23,3; li 0,0; li 5,0; sth 0,0x6bc(25); cmpw 5,23; bge 8f; addi 27,1,312; 0:; lwz 9,0xc(26); addi 5,5,1; mr 24,5; lis 4,21875; lha 3,0x90(9); ori 4,4,25970; lwz 0,0x94(9); extsh 5,5; add 3,26,3; li 6,0; mtspr 8,0; blrl; mr. 31,3; beq 7f; lwz 9,0xc(26); mr 4,31; addi 5,1,304; lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,26,3; blrl; lhz 10,0x130(1); lhz 11,0x6bc(25); extsh 9,10; extsh 0,11; cmpw 0,9; bge 1f; mr 11,10; 1:; lis 5,21875; addi 3,1,8; mr 4,31; sth 11,0x6bc(25); ori 5,5,25970; li 6,0; bl _s800EF184_1; lwz 4,0x8(1); mr 3,25; lha 5,0x130(1); bl _s800EF184_2; mr. 28,3; beq 7f; lis 3,-32697; lwz 4,0x8(1); addi 3,3,24012; bl _s800EF184_3; mr. 30,3; beq 4f; lwz 9,0x10(30); addi 29,1,312; mr 31,29; li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,31; bl _s800EF184_4; mr 3,28; mr 4,31; bl _s800EF184_5; mr 3,31; li 4,2; bl _s800EF184_6; lwz 3,0x14(30); li 4,0; cmpwi 3,0; beq 3f; lwz 4,0x0(3); 3:; mr 3,29; bl _s800EF184_7; mr 3,28; mr 4,31; bl _s800EF184_8; mr 3,31; li 4,2; bl _s800EF184_9; b 5f; 4:; addi 4,1,16; mr 3,27; bl _s800EF184_10; mr 3,28; mr 4,27; bl _s800EF184_11; mr 3,27; li 4,2; bl _s800EF184_12; addi 4,1,80; mr 3,27; bl _s800EF184_13; mr 3,28; mr 4,27; bl _s800EF184_14; mr 3,27; li 4,2; bl _s800EF184_15; 5:; li 3,292; bl _s800EF184_16; mr 11,22; mr 9,3; li 10,288; 6:; lwz 0,0x0(11); addic. 10,10,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 6b; lwz 0,0x0(11); stw 0,0x0(9); stw 3,0x8c(28); 7:; mr 5,24; cmpw 5,23; blt 0b; 8:; lwz 0,0x16c(1); mtspr 8,0; lmw 22,0x140(1); addi 1,1,360"

extern "C" void _s800EF184_0();
extern "C" void _s800EF184_1();
extern "C" void _s800EF184_2();
extern "C" void _s800EF184_3();
extern "C" void _s800EF184_4();
extern "C" void _s800EF184_5();
extern "C" void _s800EF184_6();
extern "C" void _s800EF184_7();
extern "C" void _s800EF184_8();
extern "C" void _s800EF184_9();
extern "C" void _s800EF184_10();
extern "C" void _s800EF184_11();
extern "C" void _s800EF184_12();
extern "C" void _s800EF184_13();
extern "C" void _s800EF184_14();
extern "C" void _s800EF184_15();
extern "C" void _s800EF184_16();

struct ObjectFolderImpl {
    void LoadUserData();
};

void ObjectFolderImpl::LoadUserData() {
}
