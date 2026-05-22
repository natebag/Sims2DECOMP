// 0x8028CD28 TArray<ENDummyPoint, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8028EA74" lines="lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 1:; addi 29,30,12; mr 3,29; bl _s8028CD28_0; cmpwi 3,0; bne 2f; mr 3,29; li 4,0; bl _s8028CD28_1; b 2f; lwz 3,-23020(13); li 4,20; bl _s8028CD28_2; bl _s8028CD28_3; mr 30,3; 2:; lwz 11,0x1c(31); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028CD28_4; 3:; lwz 0,0x1c(31); mr 3,30; stw 0,0xc(30)"
extern "C" void _s8028CD28_0();
extern "C" void _s8028CD28_1();
extern "C" void _s8028CD28_2();
extern "C" void _s8028CD28_3();
extern "C" void _s8028CD28_4();
extern "C" void f_8028EA74();
extern "C" void f_8028CD28() {}
