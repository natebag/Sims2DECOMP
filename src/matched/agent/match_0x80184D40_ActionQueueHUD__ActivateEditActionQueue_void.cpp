// 0x80184D40 ActionQueueHUD::ActivateEditActionQueue(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; lwz 4,0x150(31); cmpwi 4,0; beq 0f; li 0,2; li 9,-1; addi 4,4,-1; stb 0,0x318(31); stb 9,0x319(31); extsb 4,4; bl _s80184D40_0; lwz 4,0x314(31); lwz 3,-26524(13); bl _s80184D40_1; mr 30,3; lis 5,-32705; li 6,100; addi 5,5,-22524; li 4,0; bl _s80184D40_2; lis 9,-32705; mr 8,3; lwz 6,-22500(9); addi 11,1,8; addi 9,9,-22500; mr 3,30; stw 6,0x8(1); mr 4,8; lwz 29,0x10(9); mr 5,11; lwz 7,0x4(9); li 6,5; lwz 10,0x8(9); lwz 0,0xc(9); stw 8,0x310(31); stw 7,0x4(11); stw 10,0x8(11); stw 0,0xc(11); stw 29,0x10(11); bl _s80184D40_3; 0:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s80184D40_0();
extern "C" void _s80184D40_1();
extern "C" void _s80184D40_2();
extern "C" void _s80184D40_3();
extern "C" void f_80184D40() {}
