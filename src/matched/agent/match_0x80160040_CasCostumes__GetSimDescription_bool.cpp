// 0x80160040 CasCostumes::GetSimDescription(bool, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-344(1); mfspr 0,8; stmw 27,0x144(1); stw 0,0x15c(1); mr 31,3; mr 28,5; mr 27,4; addi 3,1,8; bl _s80160040_0; subfic 0,27,0; adde 30,0,27; addi 4,1,12; li 5,32; mr 3,28; bl _s80160040_1; rlwinm 30,30,4,0,27; addi 0,1,8; add 29,30,31; lwzx 4,30,31; lwz 5,0x4(29); lis 7,-32746; stw 0,0x138(1); addi 3,1,304; addi 7,7,-2592; addi 6,1,312; li 8,0; bl _s80160040_2; lwz 3,0x130(1); lwz 0,0x4(29); cmpw 3,0; beq 0f; lwz 3,0x0(3); b 2f; 0:; lis 30,-32706; mr 3,28; addi 4,30,-5516; li 5,2; bl _s80160040_3; cmpwi 3,0; beq 1f; mr 3,31; mr 4,27; addi 5,30,-5516; bl _s80160040_4; b 2f; 1:; li 3,0; 2:; lwz 0,0x15c(1); mtspr 8,0; lmw 27,0x144(1); addi 1,1,344"
extern "C" void _s80160040_0();
extern "C" void _s80160040_1();
extern "C" void _s80160040_2();
extern "C" void _s80160040_3();
extern "C" void _s80160040_4();
extern "C" void f_80160040() {}
