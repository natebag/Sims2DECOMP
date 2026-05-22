// 0x802B62B8 AptPrototype::~AptPrototype(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32703; mr 31,3; addi 9,9,21256; mr 30,4; stw 9,0x8(31); addi 3,31,12; li 4,2; bl _s802B62B8_0; mr 3,31; li 4,0; bl _s802B62B8_1; andi. 0,30,1; beq 0f; lwz 3,-23016(13); mr 4,31; li 5,36; bl _s802B62B8_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B62B8_0();
extern "C" void _s802B62B8_1();
extern "C" void _s802B62B8_2();
extern "C" void f_802B62B8() {}
