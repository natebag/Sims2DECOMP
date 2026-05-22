// 0x80337AB0 VideoDecoderForOnMemory(void (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); lis 9,-32691; stw 3,0x8(1); addi 9,9,14656; li 29,0; lwz 30,0xbc(9); mr 26,9; lis 27,-32691; 0:; lbz 0,0xa7(26); cmpwi 0,0; beq 5f; lwz 0,0xd8(26); cmpwi 0,0; bge 5f; lis 9,-32691; addi 28,9,14656; 1:; bl _s80337AB0_0; addi 31,27,14656; cmpwi 3,0; li 3,1; bne 2f; li 3,0; 2:; lwz 9,0xd8(31); addi 9,9,1; stw 9,0xd8(31); bl _s80337AB0_1; lwz 11,0xc0(31); lwz 9,0x50(31); add 11,29,11; divwu 0,11,9; addi 10,9,-1; mullw 0,0,9; subf 11,0,11; cmpw 11,10; bne 3f; lbz 0,0xa6(31); andi. 9,0,1; beq 5f; lwz 9,0x8(1); lwz 0,0xb4(31); lwz 30,0x0(9); stw 0,0x8(1); b 4f; 3:; lwz 9,0x8(1); add 0,9,30; lwz 9,0x0(9); stw 0,0x8(1); mr 30,9; 4:; lwz 0,0xd8(28); addi 29,29,1; cmpwi 0,0; blt 1b; 5:; stw 29,0xc(1); addi 3,1,8; bl _s80337AB0_2; addi 8,27,14656; lwz 11,0xc0(8); lwz 9,0x50(8); add 11,29,11; divwu 0,11,9; addi 10,9,-1; mullw 0,0,9; subf 11,0,11; cmpw 11,10; bne 7f; lbz 0,0xa6(8); andi. 9,0,1; beq 6f; lwz 9,0x8(1); lwz 0,0xb4(8); lwz 30,0x0(9); stw 0,0x8(1); b 8f; 6:; lis 3,-32691; addi 3,3,4704; bl _s80337AB0_3; b 8f; 7:; lwz 9,0x8(1); add 0,9,30; lwz 9,0x0(9); stw 0,0x8(1); mr 30,9; 8:; addi 29,29,1; b 0b"
extern "C" void _s80337AB0_0();
extern "C" void _s80337AB0_1();
extern "C" void _s80337AB0_2();
extern "C" void _s80337AB0_3();
extern "C" void f_80337AB0() {}
