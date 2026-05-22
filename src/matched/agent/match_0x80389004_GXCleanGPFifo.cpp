// 0x80389004 __GXCleanGPFifo (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-168(1); stw 31,0xa4(1); stw 30,0xa0(1); stw 29,0x9c(1); bl _s80389004_0; mr. 31,3; beq 4f; bl _s80389004_1; li 0,16; lwz 29,0x0(31); mtspr 9,0; addi 30,3,0; addi 5,1,12; addi 4,31,-8; 0:; lwzu 3,0x8(4); lwz 0,0x4(4); stwu 3,0x8(5); stw 0,0x4(5); bdnz 0b; bl _s80389004_2; stw 29,0x28(1); li 0,0; stw 29,0x2c(1); stw 0,0x30(1); lwz 4,0x30(1); cmpwi 4,0; bge 1f; lwz 0,0x1c(1); add 0,4,0; stw 0,0x30(1); 1:; bl _s80389004_3; addi 3,1,20; bl _s80389004_4; cmplw 30,31; bne 2f; addi 3,1,20; bl _s80389004_5; 2:; bl _s80389004_6; stw 29,0x14(31); li 0,0; stw 29,0x18(31); stw 0,0x1c(31); lwz 4,0x1c(31); cmpwi 4,0; bge 3f; lwz 0,0x8(31); add 0,4,0; stw 0,0x1c(31); 3:; bl _s80389004_7; mr 3,31; bl _s80389004_8; cmplw 30,31; bne 4f; mr 3,30; bl _s80389004_9; 4:; lwz 0,0xac(1); lwz 31,0xa4(1); lwz 30,0xa0(1); lwz 29,0x9c(1); addi 1,1,168; mtspr 8,0"
extern "C" void _s80389004_0();
extern "C" void _s80389004_1();
extern "C" void _s80389004_2();
extern "C" void _s80389004_3();
extern "C" void _s80389004_4();
extern "C" void _s80389004_5();
extern "C" void _s80389004_6();
extern "C" void _s80389004_7();
extern "C" void _s80389004_8();
extern "C" void _s80389004_9();
extern "C" void f_80389004() {}
