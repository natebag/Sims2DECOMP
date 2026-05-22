// 0x801BED54 K2YTarget::GetKeybits(int, (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 24,0x78(1); stw 0,0x9c(1); lis 9,-32705; addi 30,1,40; lwz 0,0x1f00(9); addi 29,1,8; addi 9,9,7936; mr 6,4; lbz 11,0x4(9); mr 26,5; stw 0,0x8(1); lis 28,-32705; stb 11,0x4(29); addi 5,28,7944; li 4,32; mr 3,30; crxor 6,6,6; bl _s801BED54_0; li 25,0; addi 27,1,104; stb 25,0x47(1); mr 4,30; mr 3,29; bl _s801BED54_1; mr 24,30; addi 5,28,7944; mr 6,26; li 4,32; mr 3,30; crxor 6,6,6; bl _s801BED54_2; mr 31,27; mr 4,30; mr 3,29; stb 25,0x48(1); li 28,11; bl _s801BED54_3; lis 26,-32705; mr 3,27; addi 29,1,112; bl _s801BED54_4; lis 27,-32697; addi 30,1,72; 0:; addi 4,1,8; mr 3,30; bl _s801BED54_5; addi 5,26,7948; mr 6,28; li 4,32; mr 3,24; crxor 6,6,6; bl _s801BED54_6; li 0,0; mr 4,24; stb 0,0x47(1); mr 3,30; bl _s801BED54_7; addi 4,27,24012; mr 3,29; mr 5,30; crxor 6,6,6; bl _s801BED54_8; lwz 9,0x70(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,31; rlwinm 25,25,1,0,30; bl _s801BED54_9; mr 3,31; bl _s801BED54_10; cmpwi 3,1; bne 2f; lis 4,-32705; mr 3,31; addi 4,4,7140; li 5,0; bl _s801BED54_11; cmpwi 3,0; beq 2f; lis 4,-32705; mr 3,31; addi 4,4,6544; li 5,0; bl _s801BED54_12; cmpwi 3,0; beq 2f; lis 4,-32705; mr 3,31; addi 4,4,7956; li 5,0; bl _s801BED54_13; cmpwi 3,0; beq 2f; lis 4,-32705; mr 3,31; addi 4,4,7960; li 5,0; bl _s801BED54_14; cmpwi 3,0; beq 2f; lis 4,-32705; mr 3,31; addi 4,4,7964; li 5,0; bl _s801BED54_15; cmpwi 3,0; beq 2f; ori 25,25,1; 2:; addic. 28,28,-1; bge 0b; mr 3,31; li 4,2; bl _s801BED54_16; mr 3,25; lwz 0,0x9c(1); mtspr 8,0; lmw 24,0x78(1); addi 1,1,152"
extern "C" void _s801BED54_0();
extern "C" void _s801BED54_1();
extern "C" void _s801BED54_2();
extern "C" void _s801BED54_3();
extern "C" void _s801BED54_4();
extern "C" void _s801BED54_5();
extern "C" void _s801BED54_6();
extern "C" void _s801BED54_7();
extern "C" void _s801BED54_8();
extern "C" void _s801BED54_9();
extern "C" void _s801BED54_10();
extern "C" void _s801BED54_11();
extern "C" void _s801BED54_12();
extern "C" void _s801BED54_13();
extern "C" void _s801BED54_14();
extern "C" void _s801BED54_15();
extern "C" void _s801BED54_16();
extern "C" void f_801BED54() {}
