// 0x80239BC4 EmitterSpr3d::Create(char (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,6; li 7,0; li 8,0; li 9,0; li 10,0; bl _s80239BC4_0; mr 30,3; cmpwi 30,-1; beq 0f; mr 3,31; bl _s80239BC4_1; li 0,0; mr 8,3; lis 4,-32732; lis 5,-32732; lis 6,-32732; stw 0,0xc(1); stw 0,0x8(1); li 9,0; addi 4,4,-28112; addi 5,5,-29384; addi 6,6,-26016; li 7,0; li 10,0; mr 3,31; bl _s80239BC4_2; mr 3,31; bl _s80239BC4_3; mr 9,3; lwz 0,0x16c(29); lwz 4,0x88(9); mr 3,31; stw 0,0x80(9); bl _s80239BC4_4; mr 3,30; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80239BC4_0();
extern "C" void _s80239BC4_1();
extern "C" void _s80239BC4_2();
extern "C" void _s80239BC4_3();
extern "C" void _s80239BC4_4();
extern "C" void f_80239BC4() {}
