// 0x8035CE84 ENCamera::Read(unsigned (420 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 26,0x50(1); stw 0,0x6c(1); mr 31,4; mr 28,3; addi 3,1,72; li 5,4; mr 26,31; bl _s8035CE84_0; addi 31,31,4; lwz 0,0x48(1); cmpwi 0,0; bne 5f; mr 4,31; li 5,64; mr 3,28; addi 31,31,64; bl _s8035CE84_1; li 29,0; mr 4,31; li 5,4; addi 3,28,64; addi 31,31,4; bl _s8035CE84_2; mr 4,31; li 5,4; addi 3,28,68; addi 31,31,4; bl _s8035CE84_3; lwz 4,0x44(28); addi 3,28,72; li 5,0; bl _s8035CE84_4; lwz 0,0x44(28); cmpw 29,0; bge 1f; li 27,0; 0:; lwz 30,0x48(28); mr 4,31; li 5,4; addi 31,31,4; add 30,30,27; addi 29,29,1; mr 3,30; addi 27,27,96; bl _s8035CE84_5; mr 4,31; li 5,12; addi 3,30,4; addi 31,31,12; bl _s8035CE84_6; mr 4,31; li 5,64; addi 3,30,16; addi 31,31,64; bl _s8035CE84_7; mr 4,31; li 5,4; addi 3,30,80; addi 31,31,4; bl _s8035CE84_8; mr 4,31; li 5,4; addi 3,30,84; addi 31,31,4; bl _s8035CE84_9; mr 4,31; li 5,4; addi 3,30,88; addi 31,31,4; bl _s8035CE84_10; mr 4,31; addi 3,30,92; li 5,4; addi 31,31,4; bl _s8035CE84_11; lwz 0,0x44(28); cmpw 29,0; blt 0b; 1:; addi 3,1,8; mr 4,28; bl _s8035CE84_12; li 29,0; li 30,0; addi 27,1,8; b 4f; 2:; lbzx 0,27,30; cmpwi 0,32; beq 3f; stbx 0,28,29; addi 29,29,1; 3:; addi 30,30,1; 4:; addi 3,1,8; bl _s8035CE84_13; cmpw 30,3; blt 2b; li 0,0; stbx 0,28,29; 5:; subf 3,26,31; lwz 0,0x6c(1); mtspr 8,0; lmw 26,0x50(1); addi 1,1,104"
extern "C" void _s8035CE84_0();
extern "C" void _s8035CE84_1();
extern "C" void _s8035CE84_2();
extern "C" void _s8035CE84_3();
extern "C" void _s8035CE84_4();
extern "C" void _s8035CE84_5();
extern "C" void _s8035CE84_6();
extern "C" void _s8035CE84_7();
extern "C" void _s8035CE84_8();
extern "C" void _s8035CE84_9();
extern "C" void _s8035CE84_10();
extern "C" void _s8035CE84_11();
extern "C" void _s8035CE84_12();
extern "C" void _s8035CE84_13();
extern "C" void f_8035CE84() {}
