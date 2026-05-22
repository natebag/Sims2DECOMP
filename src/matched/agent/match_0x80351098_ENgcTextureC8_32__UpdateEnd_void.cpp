// 0x80351098 ENgcTextureC8_32::UpdateEnd(void) (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x98(31); cmpwi 0,1; beq 6f; lwz 0,0xd4(31); cmpwi 0,0; bne 0f; lwz 0,0x8(31); andi. 9,0,128; bne 5f; 0:; lhz 0,0x14(31); li 7,0; cmplw 7,0; bge 4f; li 5,0; li 6,0; 1:; lwz 0,0xd4(31); cmpwi 0,0; beq 2f; add 8,0,6; b 3f; 2:; lwz 0,0x90(31); add 8,0,5; 3:; lwz 11,0xcc(31); add 10,7,7; lbz 0,0x1(8); addi 7,7,1; addi 5,5,4; addi 6,6,4; stbx 0,10,11; lwz 9,0xcc(31); lbz 0,0x0(8); add 9,10,9; stb 0,0x1(9); lwz 11,0xd0(31); lbz 0,0x3(8); stbx 0,10,11; lwz 9,0xd0(31); lbz 11,0x2(8); add 10,10,9; stb 11,0x1(10); lhz 0,0x14(31); cmplw 7,0; blt 1b; 4:; lwz 4,0xd4(31); cmpwi 4,0; beq 5f; lis 3,-32692; addi 3,3,-7364; bl _s80351098_0; li 0,0; stw 0,0xd4(31); 5:; lhz 4,0x14(31); lwz 3,0xcc(31); rlwinm 4,4,1,0,30; bl _s80351098_1; lhz 4,0x14(31); lwz 3,0xd0(31); rlwinm 4,4,1,0,30; bl _s80351098_2; 6:; lwz 4,0xd4(31); cmpwi 4,0; beq 7f; lis 3,-32692; addi 3,3,-7364; bl _s80351098_3; li 0,0; stw 0,0xd4(31); 7:; mr 3,31; bl _s80351098_4; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80351098_0();
extern "C" void _s80351098_1();
extern "C" void _s80351098_2();
extern "C" void _s80351098_3();
extern "C" void _s80351098_4();
extern "C" void f_80351098() {}
