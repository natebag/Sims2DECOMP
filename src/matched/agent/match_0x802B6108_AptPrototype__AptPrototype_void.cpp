// 0x802B6108 AptPrototype::AptPrototype(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,28; bl _s802B6108_0; lis 9,-32703; addi 3,30,12; addi 9,9,8984; li 4,8; stw 9,0x8(30); bl _s802B6108_1; lwz 0,0x0(30); li 11,0; lis 9,-32703; mr 3,30; addi 9,9,21256; rlwimi 0,11,26,5,5; stw 9,0x8(30); stw 0,0x0(30); stw 11,0x20(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B6108_0();
extern "C" void _s802B6108_1();
extern "C" void f_802B6108() {}
