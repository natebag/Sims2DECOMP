// 0x80364564 __static_initialization_and_destruction_0 (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 30,-32688; lis 3,-32688; lis 4,-32714; lis 5,-32714; lis 6,-32714; lis 8,-32702; addi 4,4,18052; addi 5,5,18104; addi 6,6,18120; addi 8,8,12228; li 7,0; addi 9,30,-13320; addi 3,3,-10564; bl _s80364564_0; stw 3,-22452(13); lis 4,-32714; lis 3,-32688; lis 5,-32714; lis 6,-32714; lis 8,-32702; addi 4,4,18388; addi 5,5,18428; addi 6,6,18460; addi 8,8,12244; li 7,0; addi 9,30,-13320; addi 3,3,-10524; bl _s80364564_1; stw 3,-22448(13); lis 4,-32714; lis 3,-32688; lis 5,-32714; lis 6,-32714; lis 8,-32702; addi 4,4,18728; addi 5,5,18768; addi 6,6,18800; addi 8,8,12256; li 7,0; addi 9,30,-13320; addi 3,3,-10484; bl _s80364564_2; stw 3,-22444(13); lis 4,-32714; lis 3,-32688; lis 5,-32714; lis 6,-32714; lis 8,-32702; addi 3,3,-10444; addi 4,4,19088; addi 5,5,19128; addi 6,6,19160; addi 8,8,12268; addi 9,30,-13320; li 7,0; bl _s80364564_3; stw 3,-22440(13); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80364564_0();
extern "C" void _s80364564_1();
extern "C" void _s80364564_2();
extern "C" void _s80364564_3();
extern "C" void f_80364564() {}
