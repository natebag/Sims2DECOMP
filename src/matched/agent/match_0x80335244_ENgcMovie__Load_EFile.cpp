// 0x80335244 ENgcMovie::Load(EFile (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 4,5; mr 31,3; li 5,0; bl _s80335244_0; cmpwi 3,0; bne 0f; lis 3,-32702; lis 5,-32702; addi 3,3,6652; addi 5,5,6728; li 4,325; crxor 6,6,6; bl _s80335244_1; 0:; addi 4,31,40; mr 3,31; bl _s80335244_2; mr 3,31; addi 4,31,52; bl _s80335244_3; lis 9,-32691; li 11,0; addi 30,9,21688; lwz 0,0x34c(30); cmpwi 0,0; beq 1f; addi 11,30,868; 1:; cmpwi 11,0; stw 11,0x24(31); bne 3f; lis 3,-32692; addi 3,3,28440; bl _s80335244_4; lwz 0,0x34c(30); li 9,0; cmpwi 0,0; beq 2f; addi 9,30,868; 2:; stw 9,0x24(31); 3:; lwz 11,0x24(31); addi 30,31,68; lwz 0,0x28(31); lhz 9,0x4(11); lwz 8,-26824(13); subf 9,0,9; lwz 10,0x2c(31); rlwinm 9,9,31,1,31; stw 9,0x18(31); lhz 0,0x6(11); subf 0,10,0; rlwinm 0,0,31,1,31; stw 0,0x1c(31); lwz 9,0x338(8); lwz 0,0x7c(9); lha 3,0x78(9); mtspr 8,0; add 3,8,3; blrl; mr 4,3; mr 3,30; bl _s80335244_5; mr 4,30; mr 3,31; bl _s80335244_6; li 0,0; mr 3,31; stw 0,0xc(31); li 4,0; li 5,0; li 6,0; bl _s80335244_7; cmpwi 3,0; bne 4f; lis 3,-32702; lis 5,-32702; addi 3,3,6652; addi 5,5,6756; li 4,351; crxor 6,6,6; bl _s80335244_8; 4:; li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80335244_0();
extern "C" void _s80335244_1();
extern "C" void _s80335244_2();
extern "C" void _s80335244_3();
extern "C" void _s80335244_4();
extern "C" void _s80335244_5();
extern "C" void _s80335244_6();
extern "C" void _s80335244_7();
extern "C" void _s80335244_8();
extern "C" void f_80335244() {}
