// 0x800C8D58 Neighbor::Neighbor(short, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 27,5; sth 4,0x4(30); li 5,64; stw 27,0xc(30); addi 4,30,48; addi 3,30,40; li 29,19; bl _s800C8D58_0; addi 3,30,272; bl _s800C8D58_1; li 3,240; bl _s800C8D58_2; mr 28,3; mr 31,28; 0:; mr 3,31; bl _s800C8D58_3; addi 31,31,12; cmpwi 29,0; addi 29,29,-1; bne 0b; stw 28,0x194(30); lwz 3,0xc(30); bl _s800C8D58_4; stw 3,0x8(30); bl _s800C8D58_5; stw 3,0x10(30); addi 4,30,40; mr 3,27; bl _s800C8D58_6; addi 3,30,408; li 4,0; li 5,28; bl _s800C8D58_7; li 0,0; mr 3,30; stw 0,0x1b4(30); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800C8D58_0();
extern "C" void _s800C8D58_1();
extern "C" void _s800C8D58_2();
extern "C" void _s800C8D58_3();
extern "C" void _s800C8D58_4();
extern "C" void _s800C8D58_5();
extern "C" void _s800C8D58_6();
extern "C" void _s800C8D58_7();
extern "C" void f_800C8D58() {}
