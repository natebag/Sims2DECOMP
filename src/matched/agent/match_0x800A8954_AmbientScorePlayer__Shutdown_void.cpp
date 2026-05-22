// 0x800A8954 AmbientScorePlayer::Shutdown(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s800A8954_0; cmpwi 3,0; li 3,0; beq 4f; mr 3,30; bl _s800A8954_1; lwz 9,0x8(30); cmpwi 9,0; beq 0f; lwz 4,0x8(9); lis 3,-32693; addi 3,3,7704; li 5,1; bl _s800A8954_2; li 0,0; stw 0,0x8(30); 0:; lwz 9,0xc(30); cmpwi 9,0; beq 3f; lwz 0,-8(9); mulli 0,0,48; add 31,9,0; cmpw 9,31; beq 2f; 1:; addi 31,31,-48; li 4,0; mr 3,31; bl _s800A8954_3; lwz 0,0xc(30); cmpw 0,31; bne 1b; 2:; lwz 3,0xc(30); addi 3,3,-8; bl _s800A8954_4; li 0,0; stw 0,0xc(30); 3:; li 0,0; li 3,1; stw 0,0x10(30); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A8954_0();
extern "C" void _s800A8954_1();
extern "C" void _s800A8954_2();
extern "C" void _s800A8954_3();
extern "C" void _s800A8954_4();
extern "C" void f_800A8954() {}
