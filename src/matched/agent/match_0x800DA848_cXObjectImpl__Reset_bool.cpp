// 0x800DA848 cXObjectImpl::Reset(bool) (1100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 25,0x6c(1); stw 0,0x8c(1); lis 9,-32706; mr 31,3; lfs f0,-20904(9); li 0,0; mr 26,4; addi 30,1,32; stfs f0,0xe0(31); addi 3,1,8; mr 4,31; stw 0,0xe4(31); stw 0,0xdc(31); addi 29,31,40; bl _s800DA848_0; mr 25,30; addi 27,1,80; mr 3,31; bl _s800DA848_1; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x464(9); lha 3,0x460(9); mtspr 8,0; add 3,11,3; blrl; mr 28,3; mr 4,29; mr 3,30; bl _s800DA848_2; mr 3,29; bl _s800DA848_3; li 4,29; mr 3,30; bl _s800DA848_4; lha 5,0x0(3); li 4,29; mr 3,29; bl _s800DA848_5; li 4,1; mr 3,30; bl _s800DA848_6; lha 5,0x0(3); li 4,1; mr 3,29; bl _s800DA848_7; li 4,41; mr 3,30; bl _s800DA848_8; lha 5,0x0(3); li 4,41; mr 3,29; bl _s800DA848_9; li 4,45; mr 3,30; bl _s800DA848_10; lha 5,0x0(3); li 4,45; mr 3,29; bl _s800DA848_11; li 4,46; mr 3,30; bl _s800DA848_12; lha 5,0x0(3); li 4,46; mr 3,29; bl _s800DA848_13; li 4,47; mr 3,30; bl _s800DA848_14; lha 5,0x0(3); li 4,47; mr 3,29; bl _s800DA848_15; li 4,24; mr 3,30; bl _s800DA848_16; lha 5,0x0(3); li 4,24; mr 3,29; bl _s800DA848_17; li 4,21; mr 3,30; bl _s800DA848_18; lha 5,0x0(3); li 4,21; mr 3,29; bl _s800DA848_19; li 4,67; mr 3,30; bl _s800DA848_20; lha 5,0x0(3); li 4,67; mr 3,29; bl _s800DA848_21; lha 5,0x64(31); li 4,11; mr 3,29; bl _s800DA848_22; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lha 5,0x62(3); li 4,58; mr 3,29; bl _s800DA848_23; lwz 11,0x4(31); mr 4,28; lwz 9,0x4(11); lwz 0,0x46c(9); lha 3,0x468(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0xc(31); li 10,0; cmpw 10,0; bge 1f; li 8,0; 0:; lwz 11,0x8(31); add 9,10,10; addi 10,10,1; sthx 8,9,11; lwz 0,0xc(31); cmpw 10,0; blt 0b; 1:; li 11,8; addi 28,31,40; mtspr 9,11; li 0,0; addi 9,31,36; 2:; sth 0,0x0(9); addi 9,9,-2; bdnz 2b; lwz 11,0x4(31); li 4,1; lwz 9,0x4(11); lwz 0,0x1d4(9); lha 3,0x1d0(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(31); mr 29,3; subfic 0,29,0; adde 4,0,29; lwz 11,0x0(9); lwz 9,0x18(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(31); lwz 30,0x0(31); lwz 9,0x4(11); lha 3,0x378(9); lwz 0,0x37c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 5,29; mr 3,30; bl _s800DA848_24; addi 4,1,8; mr 3,31; bl _s800DA848_25; mr 3,27; mr 4,31; bl _s800DA848_26; lwz 9,0x5c(1); cmpwi 9,0; beq 3f; lwz 3,0x4(9); lwz 9,0x4(3); lha 0,0x328(9); lwz 9,0x32c(9); add 3,3,0; mtspr 8,9; blrl; b 4f; 3:; li 3,0; 4:; extsh 5,3; li 4,2; mr 3,28; bl _s800DA848_27; lha 5,0x62(1); li 4,3; mr 3,28; bl _s800DA848_28; mr 3,31; bl _s800DA848_29; lwz 11,0x4(31); li 4,-1; lwz 9,0x4(11); lwz 0,0x24c(9); lha 3,0x248(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); lwz 9,0x0(11); lwz 0,0x19c(9); lha 3,0x198(9); mtspr 8,0; add 3,11,3; blrl; lwz 4,0x4(31); bl _s800DA848_30; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x390(9); lwz 0,0x394(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 6f; lwz 3,0x4(31); li 4,0; li 5,0; li 6,0; lwz 9,0x4(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 26,0; beq 5f; lis 9,-32697; lwz 0,0x5c74(9); cmpwi 0,0; bne 5f; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x88(11); lwz 0,0x8c(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; lwz 11,0x4(31); li 4,0; lwz 10,0x0(11); lwz 9,0x18(10); lha 3,0x20(9); lwz 0,0x24(9); add 3,10,3; mtspr 8,0; blrl; 5:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; 6:; mr 3,25; li 4,2; bl _s800DA848_31; lwz 0,0x8c(1); mtspr 8,0; lmw 25,0x6c(1); addi 1,1,136"
extern "C" void _s800DA848_0();
extern "C" void _s800DA848_1();
extern "C" void _s800DA848_2();
extern "C" void _s800DA848_3();
extern "C" void _s800DA848_4();
extern "C" void _s800DA848_5();
extern "C" void _s800DA848_6();
extern "C" void _s800DA848_7();
extern "C" void _s800DA848_8();
extern "C" void _s800DA848_9();
extern "C" void _s800DA848_10();
extern "C" void _s800DA848_11();
extern "C" void _s800DA848_12();
extern "C" void _s800DA848_13();
extern "C" void _s800DA848_14();
extern "C" void _s800DA848_15();
extern "C" void _s800DA848_16();
extern "C" void _s800DA848_17();
extern "C" void _s800DA848_18();
extern "C" void _s800DA848_19();
extern "C" void _s800DA848_20();
extern "C" void _s800DA848_21();
extern "C" void _s800DA848_22();
extern "C" void _s800DA848_23();
extern "C" void _s800DA848_24();
extern "C" void _s800DA848_25();
extern "C" void _s800DA848_26();
extern "C" void _s800DA848_27();
extern "C" void _s800DA848_28();
extern "C" void _s800DA848_29();
extern "C" void _s800DA848_30();
extern "C" void _s800DA848_31();
extern "C" void f_800DA848() {}
