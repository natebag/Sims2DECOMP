// 0x8033766C AudioDecoderForOnMemory(void (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 9,-32691; stw 3,0x8(1); addi 9,9,14656; li 29,0; lwz 31,0xbc(9); mr 30,9; lis 28,-32691; 0:; stw 29,0xc(1); addi 3,1,8; bl _s8033766C_0; lwz 9,0xc0(30); lwz 11,0x50(30); add 9,29,9; divwu 0,9,11; addi 10,11,-1; addi 29,29,1; mullw 0,0,11; subf 9,0,9; cmpw 9,10; bne 2f; lbz 0,0xa6(30); addi 3,28,9680; andi. 9,0,1; beq 1f; lwz 9,0x8(1); lwz 0,0xb4(30); lwz 31,0x0(9); stw 0,0x8(1); b 0b; 1:; bl _s8033766C_1; b 0b; 2:; lwz 9,0x8(1); add 0,9,31; lwz 11,0x0(9); stw 0,0x8(1); mr 31,11; b 0b"
extern "C" void _s8033766C_0();
extern "C" void _s8033766C_1();
extern "C" void f_8033766C() {}
