// 0x800A8774 AmbientScorePlayer::Load(char (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s800A8774_0; cmpwi 3,0; bne 0f; li 3,0; b 9f; 0:; lwz 9,0x8(31); cmpwi 9,0; beq 1f; lwz 4,0x8(9); lis 3,-32693; addi 3,3,7704; li 5,1; bl _s800A8774_1; li 0,0; stw 0,0x8(31); 1:; lis 3,-32693; mr 4,30; addi 3,3,7704; li 5,0; li 6,0; bl _s800A8774_2; lwz 9,0xc(31); stw 3,0x8(31); cmpwi 9,0; beq 4f; lwz 0,-8(9); mulli 0,0,48; add 30,9,0; cmpw 9,30; beq 3f; 2:; addi 30,30,-48; li 4,0; mr 3,30; bl _s800A8774_3; lwz 0,0xc(31); cmpw 0,30; bne 2b; 3:; lwz 3,0xc(31); addi 3,3,-8; bl _s800A8774_4; li 0,0; stw 0,0xc(31); 4:; lwz 9,0x8(31); cmpwi 9,0; beq 8f; lbz 0,0x28(9); stw 0,0x18(31); lbz 30,0x29(9); mulli 3,30,48; stw 30,0x1c(31); addi 29,30,-1; ori 3,3,8; bl _s800A8774_5; addi 28,3,8; cmpwi 30,0; stw 30,-8(28); mr 30,28; beq 6f; 5:; mr 3,30; bl _s800A8774_6; addi 30,30,48; cmpwi 29,0; addi 29,29,-1; bne 5b; 6:; lwz 0,0x1c(31); li 30,0; stw 28,0xc(31); cmpw 30,0; bge 8f; li 29,0; 7:; lwz 3,0xc(31); mr 4,31; addi 30,30,1; add 3,3,29; bl _s800A8774_7; addi 29,29,48; lwz 0,0x1c(31); cmpw 30,0; blt 7b; 8:; li 3,1; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800A8774_0();
extern "C" void _s800A8774_1();
extern "C" void _s800A8774_2();
extern "C" void _s800A8774_3();
extern "C" void _s800A8774_4();
extern "C" void _s800A8774_5();
extern "C" void _s800A8774_6();
extern "C" void _s800A8774_7();
extern "C" void f_800A8774() {}
