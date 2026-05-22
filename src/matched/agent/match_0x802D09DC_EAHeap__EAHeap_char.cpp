// 0x802D09DC EAHeap::EAHeap(char (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 30,3; mr 27,4; mr 26,5; mr 25,6; mr 29,7; mr 28,8; li 6,1; li 7,0; li 8,0; li 4,0; li 5,0; li 9,0; bl _s802D09DC_0; stw 27,0x528(30); mr 3,30; stw 29,0x52c(30); stw 28,0x530(30); bl _s802D09DC_1; mr 4,26; mr 5,25; mr 3,30; bl _s802D09DC_2; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s802D09DC_0();
extern "C" void _s802D09DC_1();
extern "C" void _s802D09DC_2();
extern "C" void f_802D09DC() {}
