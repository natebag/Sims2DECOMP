// 0x80165250 CasScene::~CasScene(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,24648; mr 28,4; stw 9,0x4(30); lwz 3,0xa80(30); cmpwi 3,0; beq 0f; bl _s80165250_0; li 0,0; stw 0,0xa80(30); 0:; lwz 3,0xa84(30); cmpwi 3,0; beq 1f; bl _s80165250_1; li 0,0; stw 0,0xa84(30); 1:; lwz 3,0xa88(30); cmpwi 3,0; beq 2f; li 4,3; bl _s80165250_2; 2:; lwz 10,-26392(13); li 31,0; stw 31,0xa88(30); lis 9,-32706; lfs f1,-1004(9); lwz 11,0x0(10); fmr f2,f1; lwz 0,0x1ac(11); fmr f3,f2; lha 3,0x1a8(11); fmr f4,f3; mtspr 8,0; add 3,10,3; blrl; lwz 8,-26392(13); lis 9,-32706; lfs f1,-1000(9); lis 11,-32706; lwz 9,0x0(8); lis 10,-32706; lfs f2,-996(11); fmr f3,f1; lha 3,0x1b0(9); lwz 0,0x1b4(9); add 3,8,3; lfs f4,-992(10); mtspr 8,0; blrl; lwz 3,0xa8c(30); cmpwi 3,0; beq 3f; bl _s80165250_3; stw 31,0xa8c(30); 3:; lwz 11,0xb18(30); cmpwi 11,0; beq 4f; lwz 9,0x9c(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 4:; lwz 3,0xac0(30); stw 31,0xb18(30); cmpwi 3,0; beq 6f; bl _s80165250_4; lwz 3,0xac0(30); cmpwi 3,0; beq 5f; li 4,3; bl _s80165250_5; 5:; stw 31,0xac0(30); 6:; addic. 0,30,256; mr 29,0; beq 8f; addi 31,30,2688; cmpw 29,31; beq 8f; 7:; addi 31,31,-608; li 4,2; addi 3,31,432; bl _s80165250_6; addi 3,31,248; li 4,2; bl _s80165250_7; cmpw 29,31; bne 7b; 8:; lis 9,-32698; andi. 0,28,1; addi 9,9,24424; stw 9,0x4(30); beq 9f; mr 3,30; bl _s80165250_8; 9:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80165250_0();
extern "C" void _s80165250_1();
extern "C" void _s80165250_2();
extern "C" void _s80165250_3();
extern "C" void _s80165250_4();
extern "C" void _s80165250_5();
extern "C" void _s80165250_6();
extern "C" void _s80165250_7();
extern "C" void _s80165250_8();
extern "C" void f_80165250() {}
