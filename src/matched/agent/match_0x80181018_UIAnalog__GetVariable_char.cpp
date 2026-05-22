// 0x80181018 UIAnalog::GetVariable(char (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,4; li 3,32; bl _s80181018_0; li 0,0; mr 28,3; stb 0,0x0(28); lbz 9,0x0(31); xori 27,9,49; subfic 0,27,0; adde 27,0,27; addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lwz 30,-26524(13); mr 4,27; mr 3,30; bl _s80181018_1; mr 4,3; mr 3,30; bl _s80181018_2; lis 9,-32697; mr 29,3; lwz 3,0x5e80(9); mr 4,27; bl _s80181018_3; mr 30,3; mr 4,31; lis 3,-32706; addi 3,3,15648; bl _s80181018_4; cmpwi 3,0; bne 1f; li 4,0; mr 3,29; mr 6,30; li 5,0; b 5f; 1:; lis 3,-32706; mr 4,31; addi 3,3,15668; bl _s80181018_5; cmpwi 3,0; bne 2f; li 4,0; b 4f; 2:; lis 3,-32706; mr 4,31; addi 3,3,15684; bl _s80181018_6; cmpwi 3,0; bne 3f; li 4,1; mr 3,29; mr 6,30; li 5,0; b 5f; 3:; lis 3,-32706; mr 4,31; addi 3,3,15700; bl _s80181018_7; cmpwi 3,0; bne 6f; li 4,1; 4:; mr 3,29; mr 6,30; li 5,1; 5:; bl _s80181018_8; lis 4,-32706; mr 3,28; addi 4,4,15664; creqv 6,6,6; bl _s80181018_9; b 7f; 6:; lis 3,-32706; mr 4,31; addi 3,3,15504; bl _s80181018_10; cmpwi 3,0; bne 7f; lis 9,-32706; addi 11,9,15716; lwz 10,0x3d64(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(28); sth 0,0x4(28); stb 8,0x6(28); 7:; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80181018_0();
extern "C" void _s80181018_1();
extern "C" void _s80181018_2();
extern "C" void _s80181018_3();
extern "C" void _s80181018_4();
extern "C" void _s80181018_5();
extern "C" void _s80181018_6();
extern "C" void _s80181018_7();
extern "C" void _s80181018_8();
extern "C" void _s80181018_9();
extern "C" void _s80181018_10();
extern "C" void f_80181018() {}
