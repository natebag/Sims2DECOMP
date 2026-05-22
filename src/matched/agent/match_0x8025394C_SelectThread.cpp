// 0x8025394C SelectThread (552 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,-24616; stw 30,0x10(1); addi 30,3,0; lwz 0,-23576(13); cmpwi 0,0; ble 0f; li 3,0; b 13f; 0:; bl _s8025394C_0; lis 4,-32768; lwz 6,0xe4(4); cmplw 3,6; addi 3,6,0; beq 1f; li 3,0; b 13f; 1:; cmplwi 6,0; beq 6f; lhz 0,0x2c8(6); cmplwi 0,2; bne 5f; cmpwi 30,0; bne 2f; lwz 4,-23584(13); lwz 0,0x2d0(6); cntlzw 4,4; cmpw 0,4; bgt 2f; li 3,0; b 13f; 2:; li 0,1; sth 0,0x2c8(6); lwz 0,0x2d0(6); rlwinm 0,0,3,0,28; add 0,31,0; stw 0,0x2dc(6); lwz 5,0x2dc(6); lwz 4,0x4(5); cmplwi 4,0; bne 3f; stw 6,0x0(5); b 4f; 3:; stw 6,0x2e0(4); 4:; stw 4,0x2e4(6); li 0,0; li 4,1; stw 0,0x2e0(6); lwz 5,0x2dc(6); stw 6,0x4(5); lwz 0,0x2d0(6); lwz 5,-23584(13); subfic 0,0,31; slw 0,4,0; or 0,5,0; stw 0,-23584(13); stw 4,-23580(13); 5:; lhz 0,0x1a2(6); rlwinm. 0,0,0,30,30; bne 6f; bl _s8025394C_1; cmplwi 3,0; beq 6f; li 3,0; b 13f; 6:; lwz 0,-23584(13); cmplwi 0,0; bne 9f; lwz 12,-27896(13); lis 30,-32768; lwz 3,0xe4(30); li 4,0; mtspr 8,12; blrl; li 0,0; stw 0,0xe4(30); addi 3,31,1840; bl _s8025394C_2; 7:; bl _s8025394C_3; 8:; lwz 0,-23584(13); cmplwi 0,0; beq 8b; bl _s8025394C_4; lwz 0,-23584(13); cmplwi 0,0; beq 7b; addi 3,31,1840; bl _s8025394C_5; 9:; li 3,0; stw 3,-23580(13); lwz 0,-23584(13); cntlzw 7,0; rlwinm 0,7,3,0,28; add 4,31,0; lwz 5,0x0(4); lwz 6,0x2e0(5); addi 30,5,0; cmplwi 6,0; bne 10f; stw 3,0x4(4); b 11f; 10:; stw 3,0x2e4(6); 11:; stw 6,0x0(4); lwz 0,0x0(4); cmplwi 0,0; bne 12f; subfic 0,7,31; lwz 4,-23584(13); li 3,1; slw 0,3,0; andc 0,4,0; stw 0,-23584(13); 12:; li 0,0; stw 0,0x2dc(30); li 0,2; lis 31,-32768; sth 0,0x2c8(30); mr 4,30; lwz 12,-27896(13); lwz 3,0xe4(31); mtspr 8,12; blrl; stw 30,0xe4(31); mr 3,30; bl _s8025394C_6; mr 3,30; bl _s8025394C_7; mr 3,30; 13:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025394C_0();
extern "C" void _s8025394C_1();
extern "C" void _s8025394C_2();
extern "C" void _s8025394C_3();
extern "C" void _s8025394C_4();
extern "C" void _s8025394C_5();
extern "C" void _s8025394C_6();
extern "C" void _s8025394C_7();
extern "C" void f_8025394C() {}
