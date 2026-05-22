// 0x80145A18 StdResFile::Open(StringBuffer (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-896(1); mfspr 0,8; stmw 23,0x35c(1); stw 0,0x384(1); mr 28,3; bl _s80145A18_0; mr. 3,3; bne 5f; mr 3,28; li 25,0; bl _s80145A18_1; li 27,0; addic. 29,3,-1; blt 3f; addi 30,1,8; addi 26,1,552; lis 23,-32706; lis 24,-32706; 0:; addi 4,30,8; li 5,260; mr 3,30; bl _s80145A18_2; addi 4,1,288; addi 3,1,280; li 5,260; bl _s80145A18_3; addi 4,1,560; addi 3,1,552; li 5,260; bl _s80145A18_4; extsh 4,29; mr 3,28; bl _s80145A18_5; mr 31,3; mr 4,30; lwz 9,0xc(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; addi 4,1,280; mr 3,30; mr 5,26; bl _s80145A18_6; addi 4,1,832; addi 3,1,824; li 5,5; bl _s80145A18_7; addi 3,1,824; addi 4,23,-10360; li 5,-1; bl _s80145A18_8; mr 3,26; addi 4,1,824; bl _s80145A18_9; cmpwi 3,0; bne 1f; mr 25,31; b 2f; 1:; addi 4,1,848; addi 3,1,840; li 5,5; bl _s80145A18_10; addi 3,1,840; addi 4,24,-10368; li 5,-1; bl _s80145A18_11; mr 3,26; addi 4,1,840; bl _s80145A18_12; cmpwi 3,0; bne 2f; mr 27,31; 2:; addic. 29,29,-1; bge 0b; 3:; cmpwi 25,0; beq 4f; cmpwi 27,0; beq 4f; lis 5,21328; mr 3,28; mr 4,27; ori 5,5,21027; bl _s80145A18_13; lis 5,17479; mr 3,28; mr 4,27; ori 5,5,21072; bl _s80145A18_14; lis 5,20545; mr 3,28; mr 4,27; ori 5,5,19540; bl _s80145A18_15; lis 5,16973; mr 3,28; mr 4,27; ori 5,5,20575; bl _s80145A18_16; lis 5,21328; mr 4,27; mr 3,28; ori 5,5,21042; bl _s80145A18_17; lis 5,21328; mr 3,28; mr 4,25; ori 5,5,21027; bl _s80145A18_18; lis 5,17479; mr 3,28; mr 4,25; ori 5,5,21072; bl _s80145A18_19; lis 5,20545; mr 3,28; mr 4,25; ori 5,5,19540; bl _s80145A18_20; lis 5,16973; mr 3,28; mr 4,25; ori 5,5,20575; bl _s80145A18_21; lis 5,21328; mr 3,28; mr 4,25; ori 5,5,21042; bl _s80145A18_22; 4:; li 3,0; 5:; lwz 0,0x384(1); mtspr 8,0; lmw 23,0x35c(1); addi 1,1,896"
extern "C" void _s80145A18_0();
extern "C" void _s80145A18_1();
extern "C" void _s80145A18_2();
extern "C" void _s80145A18_3();
extern "C" void _s80145A18_4();
extern "C" void _s80145A18_5();
extern "C" void _s80145A18_6();
extern "C" void _s80145A18_7();
extern "C" void _s80145A18_8();
extern "C" void _s80145A18_9();
extern "C" void _s80145A18_10();
extern "C" void _s80145A18_11();
extern "C" void _s80145A18_12();
extern "C" void _s80145A18_13();
extern "C" void _s80145A18_14();
extern "C" void _s80145A18_15();
extern "C" void _s80145A18_16();
extern "C" void _s80145A18_17();
extern "C" void _s80145A18_18();
extern "C" void _s80145A18_19();
extern "C" void _s80145A18_20();
extern "C" void _s80145A18_21();
extern "C" void _s80145A18_22();
extern "C" void f_80145A18() {}
