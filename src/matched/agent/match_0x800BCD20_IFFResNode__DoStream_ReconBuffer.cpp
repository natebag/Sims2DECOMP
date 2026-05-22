// 0x800BCD20 IFFResNode::DoStream(ReconBuffer (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 3,30; mr 4,31; li 5,1; bl _s800BCD20_0; lha 0,0x6(31); addi 4,1,8; mr 3,30; li 5,1; sth 0,0x8(1); bl _s800BCD20_1; lha 0,0x8(1); mr 3,30; addi 4,31,10; li 5,1; stw 0,0x4(31); bl _s800BCD20_2; lwz 0,0xc(30); cmpwi 0,0; bne 0f; lhz 0,0xa(31); sth 0,0x8(31); 0:; mr 3,30; addi 4,31,16; bl _s800BCD20_3; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800BCD20_0();
extern "C" void _s800BCD20_1();
extern "C" void _s800BCD20_2();
extern "C" void _s800BCD20_3();
extern "C" void f_800BCD20() {}
