// 0x8026B8DC AptUnRegisterExtension(AptExtObject (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 30,3; addi 29,1,8; lwz 9,0x8(30); lis 28,-32704; lis 27,-32704; lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,30,3; blrl; mr 4,3; mr 3,29; bl _s8026B8DC_0; lwz 9,0x8(30); addi 5,27,3504; li 6,1868; addi 4,28,3636; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,30,3; blrl; lwz 3,-27000(13); mr 4,29; addi 3,3,12; bl _s8026B8DC_1; lwz 9,0x8(30); addi 4,28,3636; addi 5,27,3504; li 6,1873; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026B8DC_2; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8026B8DC_0();
extern "C" void _s8026B8DC_1();
extern "C" void _s8026B8DC_2();
extern "C" void f_8026B8DC() {}
