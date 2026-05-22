// 0x803379CC VideoDecoder(void (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32691; lis 28,-32691; addi 29,9,14656; 0:; lbz 0,0xa7(29); cmpwi 0,0; beq 5f; lwz 0,0xd8(29); cmpwi 0,0; bge 4f; addi 30,28,14656; 1:; bl _s803379CC_0; mr 31,3; lwz 10,0xc0(30); lwz 0,0x4(31); lwz 11,0x50(30); add 0,0,10; divwu 9,0,11; addi 10,11,-1; mullw 9,9,11; subf 0,9,0; cmpw 0,10; bne 2f; lbz 0,0xa6(30); xori 0,0,1; andi. 9,0,1; beq 2f; bl _s803379CC_1; 2:; mr 3,31; bl _s803379CC_2; bl _s803379CC_3; cmpwi 3,0; li 3,1; bne 3f; li 3,0; 3:; lwz 9,0xd8(30); addi 9,9,1; stw 9,0xd8(30); bl _s803379CC_4; lwz 0,0xd8(30); cmpwi 0,0; blt 1b; 4:; lbz 0,0xa7(29); cmpwi 0,0; beq 5f; bl _s803379CC_5; b 6f; 5:; bl _s803379CC_6; 6:; mr 31,3; mr 3,31; bl _s803379CC_7; mr 3,31; bl _s803379CC_8; b 0b"
extern "C" void _s803379CC_0();
extern "C" void _s803379CC_1();
extern "C" void _s803379CC_2();
extern "C" void _s803379CC_3();
extern "C" void _s803379CC_4();
extern "C" void _s803379CC_5();
extern "C" void _s803379CC_6();
extern "C" void _s803379CC_7();
extern "C" void _s803379CC_8();
extern "C" void f_803379CC() {}
