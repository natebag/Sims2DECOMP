// 0x80048198 __static_initialization_and_destruction_0 (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 10f; cmpwi 3,0; beq 4f; li 10,650; lis 9,-32697; mtspr 9,10; li 11,0; addi 9,9,25452; li 0,255; 0:; stw 11,0x0(9); stb 0,0x0(9); addi 9,9,16; bdnz 0b; lis 3,-32696; li 30,71; addi 3,3,-29684; bl _s80048198_0; lis 9,-32696; addi 31,9,-29672; 1:; mr 3,31; bl _s80048198_1; addi 31,31,16; cmpwi 30,0; addi 30,30,-1; bne 1b; li 10,40; lis 9,-32696; mtspr 9,10; li 11,1; addi 9,9,-28520; li 0,0; 2:; stw 0,0x4(9); stw 0,0x0(9); stw 11,0x8(9); addi 9,9,12; bdnz 2b; li 0,3969; mtspr 9,0; 3:; bdnz 3b; lis 3,-32688; lis 4,-32763; lis 5,-32763; lis 6,-32763; lis 8,-32707; lis 9,-32688; addi 3,3,-18568; addi 4,4,-31924; addi 5,5,-31884; addi 6,6,-31852; addi 8,8,11516; addi 9,9,-18528; li 7,0; bl _s80048198_2; stw 3,-24984(13); b 10f; 4:; lis 9,-32696; addi 9,9,-28520; cmpwi 9,0; beq 6f; addi 31,9,480; cmpw 31,9; beq 6f; mr 30,9; 5:; addi 31,31,-12; mr 3,31; bl _s80048198_3; cmpw 31,30; bne 5b; 6:; lis 9,-32696; addi 9,9,-29672; cmpwi 9,0; beq 8f; addi 31,9,1152; cmpw 31,9; beq 8f; mr 30,9; 7:; addi 31,31,-16; li 4,0; mr 3,31; bl _s80048198_4; cmpw 31,30; bne 7b; 8:; lis 3,-32696; addi 3,3,-29684; bl _s80048198_5; lis 9,-32697; addi 9,9,25452; cmpwi 9,0; beq 10f; addi 11,9,10400; cmpw 11,9; beq 10f; 9:; addi 11,11,-16; cmpw 11,9; bne 9b; 10:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80048198_0();
extern "C" void _s80048198_1();
extern "C" void _s80048198_2();
extern "C" void _s80048198_3();
extern "C" void _s80048198_4();
extern "C" void _s80048198_5();
extern "C" void f_80048198() {}
