// 0x802FC110 ESubModelShader::ReadPositions(unsigned (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,0x10(3); mr 30,4; mr 29,30; mr 31,5; andi. 9,0,16; beq 1f; lwz 4,0x18(31); lis 5,-32702; lis 7,-32702; li 6,1674; addi 7,7,-2656; addi 5,5,-2744; rlwinm 4,4,3,0,28; bl _s802FC110_0; lwz 0,0x18(31); mr 9,3; mr 4,30; rlwinm 0,0,3,0,28; stw 9,0x0(31); mr 5,0; add 30,30,0; bl _s802FC110_1; lwz 4,0x18(31); lwz 3,0x0(31); rlwinm 4,4,3,0,28; bl _s802FC110_2; lwz 0,0x18(31); li 10,0; cmplw 10,0; bge 3f; li 8,0; 0:; lwz 9,0x0(31); addi 10,10,1; add 9,8,9; lhz 11,0x6(9); addi 8,8,8; sth 11,0x6(9); lwz 0,0x18(31); cmplw 10,0; blt 0b; b 3f; 1:; lwz 4,0x18(31); lis 5,-32702; lis 7,-32702; li 6,1713; addi 7,7,-2656; addi 5,5,-2744; rlwinm 4,4,4,0,27; bl _s802FC110_3; lwz 0,0x18(31); mr 9,3; mr 4,30; rlwinm 0,0,4,0,27; stw 9,0x0(31); mr 5,0; add 30,30,0; bl _s802FC110_4; lwz 4,0x18(31); lwz 3,0x0(31); rlwinm 4,4,3,0,28; bl _s802FC110_5; lwz 0,0x18(31); li 10,0; cmplw 10,0; bge 3f; 2:; lwz 0,0x18(31); addi 10,10,1; cmplw 10,0; blt 2b; 3:; subf 3,29,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802FC110_0();
extern "C" void _s802FC110_1();
extern "C" void _s802FC110_2();
extern "C" void _s802FC110_3();
extern "C" void _s802FC110_4();
extern "C" void _s802FC110_5();
extern "C" void f_802FC110() {}
