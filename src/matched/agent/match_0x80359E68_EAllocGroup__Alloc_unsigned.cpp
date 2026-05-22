// 0x80359E68 EAllocGroup::Alloc(unsigned (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,3; lwz 4,0x10(31); cmplw 29,4; bge 0f; cmpwi 5,32; ble 1f; 0:; lwz 3,0xc(31); mr 4,29; li 6,0; li 7,0; bl _s80359E68_0; mr. 30,3; beq 2f; mr 3,31; mr 4,30; bl _s80359E68_1; b 2f; 1:; lwz 0,0x14(31); addi 9,5,-1; add 0,0,9; andc 5,0,9; add 0,5,29; cmpw 0,4; blt 3f; lwz 3,0xc(31); li 5,32; li 6,0; li 7,0; bl _s80359E68_2; mr. 30,3; beq 2f; mr 3,31; mr 4,30; bl _s80359E68_3; stw 29,0x14(31); 2:; mr 3,30; b 4f; 3:; lwz 9,0x4(31); lwz 3,0x0(9); stw 0,0x14(31); add 3,3,5; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80359E68_0();
extern "C" void _s80359E68_1();
extern "C" void _s80359E68_2();
extern "C" void _s80359E68_3();
extern "C" void f_80359E68() {}
