// 0x800C8C48 Neighbor::Neighbor(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 0,0; sth 0,0x22(30); addi 4,30,48; li 5,64; sth 0,0x1c(30); sth 0,0x1e(30); addi 3,30,40; sth 0,0x20(30); li 29,19; bl _s800C8C48_0; addi 3,30,272; bl _s800C8C48_1; li 3,240; bl _s800C8C48_2; mr 28,3; mr 31,28; 0:; mr 3,31; bl _s800C8C48_3; addi 31,31,12; cmpwi 29,0; addi 29,29,-1; bne 0b; li 0,1; stw 28,0x194(30); stw 0,0x24(30); bl _s800C8C48_4; stw 3,0x10(30); addi 3,30,272; bl _s800C8C48_5; addi 3,30,408; li 4,0; li 5,28; bl _s800C8C48_6; li 0,0; mr 3,30; stw 0,0x1b4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800C8C48_0();
extern "C" void _s800C8C48_1();
extern "C" void _s800C8C48_2();
extern "C" void _s800C8C48_3();
extern "C" void _s800C8C48_4();
extern "C" void _s800C8C48_5();
extern "C" void _s800C8C48_6();
extern "C" void f_800C8C48() {}
