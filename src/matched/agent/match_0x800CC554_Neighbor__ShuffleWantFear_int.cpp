// 0x800CC554 Neighbor::ShuffleWantFear(int) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; cmpwi 31,-1; bne 1f; li 31,0; 0:; mr 4,31; mr 3,30; bl _s800CC554_0; mr 4,31; mr 3,30; li 5,2; addi 31,31,1; bl _s800CC554_1; cmplwi 31,6; ble 0b; b 2f; 1:; mr 4,31; mr 3,30; bl _s800CC554_2; mr 3,30; mr 4,31; li 5,2; bl _s800CC554_3; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800CC554_0();
extern "C" void _s800CC554_1();
extern "C" void _s800CC554_2();
extern "C" void _s800CC554_3();
extern "C" void f_800CC554() {}
