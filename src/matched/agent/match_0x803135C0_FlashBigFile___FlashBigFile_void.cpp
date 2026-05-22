// 0x803135C0 FlashBigFile::~FlashBigFile(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 31,3; mr 23,4; lwz 3,0x0(31); li 29,0; lis 22,-32693; bl _s803135C0_0; mr 27,3; cmpw 29,27; bge 4f; li 24,0; li 25,0; li 26,0; li 28,0; 0:; mr 3,31; mr 4,29; bl _s803135C0_1; cmpwi 3,0; beq 2f; lwz 9,0x4(31); lwzx 30,28,9; cmpwi 30,0; beq 3f; lwz 3,0x0(30); cmpwi 3,0; beq 1f; bl _s803135C0_2; 1:; stw 24,0x4(30); mr 3,30; stw 24,0x8(30); bl _s803135C0_3; b 3f; 2:; lwz 9,0x4(31); addi 3,22,31260; lwzx 4,26,9; bl _s803135C0_4; 3:; lwz 9,0x4(31); addi 29,29,1; addi 26,26,4; addi 28,28,4; stwx 24,25,9; cmpw 29,27; addi 25,25,4; blt 0b; 4:; lis 30,-32693; lwz 4,0x4(31); addi 3,30,31260; li 29,0; bl _s803135C0_5; stw 29,0x4(31); addi 3,30,31260; lwz 4,0x0(31); bl _s803135C0_6; stw 29,0x0(31); andi. 0,23,1; beq 5f; mr 3,31; bl _s803135C0_7; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s803135C0_0();
extern "C" void _s803135C0_1();
extern "C" void _s803135C0_2();
extern "C" void _s803135C0_3();
extern "C" void _s803135C0_4();
extern "C" void _s803135C0_5();
extern "C" void _s803135C0_6();
extern "C" void _s803135C0_7();
extern "C" void f_803135C0() {}
