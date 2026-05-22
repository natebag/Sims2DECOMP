// 0x802CC090 ENDummy::Read(unsigned (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 31,4; mr 29,3; addi 3,1,8; li 5,4; mr 26,31; bl _s802CC090_0; addi 31,31,4; lwz 0,0x8(1); cmpwi 0,0; bne 1f; mr 4,31; li 5,64; mr 3,29; addi 31,31,64; bl _s802CC090_1; li 27,0; mr 4,31; li 5,4; addi 3,29,64; addi 31,31,4; bl _s802CC090_2; mr 4,31; li 5,4; addi 3,29,68; addi 31,31,4; bl _s802CC090_3; lwz 4,0x44(29); addi 3,29,72; li 5,0; bl _s802CC090_4; lwz 0,0x44(29); cmpw 27,0; bge 1f; li 28,0; 0:; lwz 30,0x48(29); mr 4,31; li 5,4; addi 31,31,4; add 30,30,28; addi 27,27,1; mr 3,30; addi 28,28,80; bl _s802CC090_5; mr 4,31; li 5,12; addi 3,30,4; addi 31,31,12; bl _s802CC090_6; mr 4,31; addi 3,30,16; li 5,64; addi 31,31,64; bl _s802CC090_7; lwz 0,0x44(29); cmpw 27,0; blt 0b; 1:; subf 3,26,31; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s802CC090_0();
extern "C" void _s802CC090_1();
extern "C" void _s802CC090_2();
extern "C" void _s802CC090_3();
extern "C" void _s802CC090_4();
extern "C" void _s802CC090_5();
extern "C" void _s802CC090_6();
extern "C" void _s802CC090_7();
extern "C" void f_802CC090() {}
