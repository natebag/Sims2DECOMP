// 0x80147474 TreeStack::MakeNewFrame(unsigned (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80147474_0; mr 28,3; mr 3,30; bl _s80147474_1; subf 3,3,28; cmplw 3,29; bge 2f; add 31,28,28; cmpwi 31,0; bne 0f; add 4,29,29; li 31,512; cmplwi 4,512; ble 0f; mr 31,4; 0:; addi 0,31,7; rlwinm 31,0,0,0,28; mr 3,31; bl _s80147474_2; mr 29,3; lwz 4,0x0(30); mr 5,28; crxor 6,6,6; bl _s80147474_3; lwz 3,0x0(30); cmpwi 3,0; beq 1f; bl _s80147474_4; 1:; lwz 0,0x8(30); add 9,29,31; lwz 4,0xc(30); mr 3,30; stw 29,0x0(30); subf 4,0,4; stw 9,0x4(30); srawi 4,4,2; bl _s80147474_5; mr 3,30; bl _s80147474_6; mr 3,30; bl _s80147474_7; 2:; mr 3,30; bl _s80147474_8; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80147474_0();
extern "C" void _s80147474_1();
extern "C" void _s80147474_2();
extern "C" void _s80147474_3();
extern "C" void _s80147474_4();
extern "C" void _s80147474_5();
extern "C" void _s80147474_6();
extern "C" void _s80147474_7();
extern "C" void _s80147474_8();
extern "C" void f_80147474() {}
