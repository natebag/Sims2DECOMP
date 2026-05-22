// 0x80299150 AptPseudoDisplayList::Insert(AptPseudoCIH_t (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,4; addi 29,1,8; addi 28,1,12; lwz 4,0x10(30); mr 31,3; mr 5,29; mr 6,28; bl _s80299150_0; lwz 4,0xc(1); cmpwi 4,0; beq 0f; mr 3,31; bl _s80299150_1; lwz 4,0x10(30); mr 5,29; mr 3,31; mr 6,28; bl _s80299150_2; lwz 4,0x8(1); mr 3,31; mr 5,30; bl _s80299150_3; b 1f; 0:; lwz 4,0x8(1); mr 3,31; mr 5,30; bl _s80299150_4; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80299150_0();
extern "C" void _s80299150_1();
extern "C" void _s80299150_2();
extern "C" void _s80299150_3();
extern "C" void _s80299150_4();
extern "C" void f_80299150() {}
