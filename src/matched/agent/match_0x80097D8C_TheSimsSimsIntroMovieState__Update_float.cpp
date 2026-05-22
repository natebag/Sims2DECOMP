// 0x80097D8C TheSimsSimsIntroMovieState::Update(float) (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 28,0x18(1); stw 0,0x34(1); lis 9,-32706; lis 11,-32706; addi 9,9,-30288; addi 11,11,-30296; lwz 7,0x0(9); lwz 8,0x4(9); mr 30,3; lwz 9,0x0(11); lwz 10,0x4(11); li 4,26; stw 7,0x8(1); stw 8,0xc(1); addi 5,1,8; stw 9,0x10(1); stw 10,0x14(1); addi 6,1,16; lwz 3,-26524(13); li 7,0; li 8,0; li 9,-1; bl _s80097D8C_0; cmpwi 3,0; beq 0f; li 0,1; stw 0,0x20(30); 0:; lwz 0,0x20(30); lis 28,-32697; cmpwi 0,0; beq 3f; lwz 31,-26564(13); lis 10,-32706; lwz 11,0x8(30); li 29,0; lwz 9,0x0(31); lfs f0,-29720(10); lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; lfs f31,0x28(11); mtspr 8,0; fmuls f31,f31,f0; blrl; lis 9,-32706; fadds f1,f1,f31; lfs f0,-29716(9); fcmpu 0,f1,f0; bgt 1f; lis 9,-32706; lfs f0,-29712(9); fcmpu 0,f1,f0; bge 2f; 1:; fmr f1,f0; li 29,1; 2:; lwz 9,0x0(31); lis 28,-32697; lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 29,0; beq 3f; addi 3,28,-7672; bl _s80097D8C_1; 3:; lis 3,-32697; addi 3,3,-7672; bl _s80097D8C_2; cmpwi 3,0; bne 4f; addi 3,28,-7672; bl _s80097D8C_3; cmpwi 3,0; bne 4f; lis 9,-32706; mr 3,30; lfs f1,-29712(9); li 4,5; bl _s80097D8C_4; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x18(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s80097D8C_0();
extern "C" void _s80097D8C_1();
extern "C" void _s80097D8C_2();
extern "C" void _s80097D8C_3();
extern "C" void _s80097D8C_4();
extern "C" void f_80097D8C() {}
