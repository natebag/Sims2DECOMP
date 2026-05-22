// 0x8016EF38 CasSimRenderer::~CasSimRenderer(void) (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,24824; mr 30,4; stw 9,0x4(31); lwz 4,0x210(31); cmpwi 4,0; beq 1f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 11,-26392(13); lwz 4,0x210(31); lwz 9,0x0(11); lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x210(31); 1:; lwz 3,0x170(31); cmpwi 3,0; beq 2f; bl _s8016EF38_0; li 0,0; stw 0,0x170(31); 2:; lwz 4,0x204(31); cmpwi 4,0; beq 3f; lis 3,-32693; addi 3,3,11064; bl _s8016EF38_1; li 0,0; stw 0,0x204(31); 3:; addi 3,31,372; li 4,2; bl _s8016EF38_2; addi 3,31,8; li 4,2; bl _s8016EF38_3; lis 9,-32698; andi. 0,30,1; addi 9,9,24424; stw 9,0x4(31); beq 4f; mr 3,31; bl _s8016EF38_4; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8016EF38_0();
extern "C" void _s8016EF38_1();
extern "C" void _s8016EF38_2();
extern "C" void _s8016EF38_3();
extern "C" void _s8016EF38_4();
extern "C" void f_8016EF38() {}
