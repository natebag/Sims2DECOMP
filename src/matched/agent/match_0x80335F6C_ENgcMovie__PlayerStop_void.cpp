// 0x80335F6C ENgcMovie::PlayerStop(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32691; addi 31,9,14656; lwz 0,0xa0(31); cmpwi 0,0; beq 2f; lbz 0,0xa4(31); cmpwi 0,0; beq 2f; li 0,0; lwz 3,-26364(13); stb 0,0xa4(31); stb 0,0xa5(31); bl _s80335F6C_0; lwz 0,0xb0(31); cmpwi 0,0; bne 0f; mr 3,31; bl _s80335F6C_1; bl _s80335F6C_2; 0:; bl _s80335F6C_3; lbz 0,0xa7(31); cmpwi 0,0; beq 1f; bl _s80335F6C_4; 1:; bl _s80335F6C_5; mr. 3,3; bne 1b; lis 9,-32691; addi 9,9,14656; lfs f0,0xe0(9); stw 3,0xac(9); stfs f0,0xdc(9); stw 3,0xe8(9); stw 3,0xa8(9); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80335F6C_0();
extern "C" void _s80335F6C_1();
extern "C" void _s80335F6C_2();
extern "C" void _s80335F6C_3();
extern "C" void _s80335F6C_4();
extern "C" void _s80335F6C_5();
extern "C" void f_80335F6C() {}
