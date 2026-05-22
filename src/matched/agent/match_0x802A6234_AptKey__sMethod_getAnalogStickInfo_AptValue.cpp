// 0x802A6234 AptKey::sMethod_getAnalogStickInfo(AptValue (1432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); lis 9,-32694; li 31,0; lwz 0,-15972(9); li 28,503; cmpwi 0,0; beq 0f; rlwinm 31,0,30,24,31; rlwinm 28,0,15,17,31; 0:; lwz 3,-23016(13); li 4,36; addi 31,31,-2; bl _s802A6234_0; mr 29,3; li 4,27; bl _s802A6234_1; lis 9,-32703; addi 3,29,12; addi 9,9,8984; li 4,8; stw 9,0x8(29); bl _s802A6234_2; li 0,0; lis 9,-32703; stb 0,0x20(29); addi 9,9,21120; stw 9,0x8(29); lwz 0,0x20(29); lwz 5,-26908(13); rlwinm 0,0,0,10,7; cmpwi 5,0; stw 0,0x20(29); beq 3f; lwz 0,0x0(5); lwz 9,0xc(5); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(5); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(5); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 5,11,9; stw 0,0x4(8); 2:; stw 31,0xc(5); b 4f; 3:; lwz 3,-23020(13); li 4,16; bl _s802A6234_3; mr 30,3; li 4,7; bl _s802A6234_4; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 5,30; stw 9,0x8(30); 4:; lis 4,-32694; addi 3,29,12; addi 4,4,-11332; addi 30,1,8; addi 4,4,188; mr 26,3; bl _s802A6234_5; mr 25,30; lis 4,-32703; mr 3,30; addi 4,4,-21028; bl _s802A6234_6; cmpwi 28,501; bne 15f; lwz 9,-23008(13); lwz 5,-26912(13); lwz 31,0x74(9); cmpwi 5,0; beq 7f; lwz 0,0x0(5); lwz 9,0xc(5); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(5); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 5f; rlwinm 0,11,0,3,1; stw 0,0x0(5); b 6f; 5:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 5,11,9; stw 0,0x4(8); 6:; stw 31,0xc(5); mr 28,5; b 8f; 7:; lwz 3,-23020(13); li 4,16; bl _s802A6234_7; mr 30,3; li 4,6; mr 28,30; bl _s802A6234_8; lis 9,-32702; stw 31,0xc(30); addi 9,9,-26784; stw 9,0x8(30); 8:; lwz 9,-23008(13); lwz 5,-26912(13); lwz 31,0x78(9); cmpwi 5,0; beq 11f; lwz 0,0x0(5); lwz 9,0xc(5); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(5); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 9f; rlwinm 0,11,0,3,1; stw 0,0x0(5); b 10f; 9:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 5,11,9; stw 0,0x4(8); 10:; stw 31,0xc(5); mr 27,5; b 12f; 11:; lwz 3,-23020(13); li 4,16; bl _s802A6234_9; mr 30,3; li 4,6; mr 27,30; bl _s802A6234_10; lis 9,-32702; stw 31,0xc(30); addi 9,9,-26784; stw 9,0x8(30); 12:; mr 4,25; mr 5,28; mr 3,26; bl _s802A6234_11; lis 4,-32703; addi 3,1,16; addi 4,4,-21016; bl _s802A6234_12; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 13f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A6234_13; 13:; lwz 4,0x10(1); stw 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A6234_14; 14:; mr 3,26; mr 4,25; mr 5,27; bl _s802A6234_15; b 28f; 15:; cmpwi 28,502; bne 28f; lwz 9,-23008(13); lwz 5,-26912(13); lwz 31,0x84(9); cmpwi 5,0; beq 18f; lwz 0,0x0(5); lwz 9,0xc(5); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(5); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 16f; rlwinm 0,11,0,3,1; stw 0,0x0(5); b 17f; 16:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 5,11,9; stw 0,0x4(8); 17:; stw 31,0xc(5); mr 28,5; b 19f; 18:; lwz 3,-23020(13); li 4,16; bl _s802A6234_16; mr 30,3; li 4,6; mr 28,30; bl _s802A6234_17; lis 9,-32702; stw 31,0xc(30); addi 9,9,-26784; stw 9,0x8(30); 19:; lwz 9,-23008(13); lwz 5,-26912(13); lwz 31,0x88(9); cmpwi 5,0; beq 22f; lwz 0,0x0(5); lwz 9,0xc(5); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(5); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 20f; rlwinm 0,11,0,3,1; stw 0,0x0(5); b 21f; 20:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 5,11,9; stw 0,0x4(8); 21:; stw 31,0xc(5); mr 27,5; b 23f; 22:; lwz 3,-23020(13); li 4,16; bl _s802A6234_18; mr 30,3; li 4,6; mr 27,30; bl _s802A6234_19; lis 9,-32702; stw 31,0xc(30); addi 9,9,-26784; stw 9,0x8(30); 23:; lis 4,-32703; addi 3,1,16; addi 4,4,-21028; bl _s802A6234_20; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 24f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A6234_21; 24:; lwz 4,0x10(1); stw 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 25f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A6234_22; 25:; mr 4,25; mr 5,28; mr 3,26; bl _s802A6234_23; lis 4,-32703; addi 3,1,16; addi 4,4,-21016; bl _s802A6234_24; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 26f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A6234_25; 26:; lwz 4,0x10(1); stw 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 27f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A6234_26; 27:; mr 3,26; mr 4,25; mr 5,27; bl _s802A6234_27; 28:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 29f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A6234_28; 29:; mr 3,29; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s802A6234_0();
extern "C" void _s802A6234_1();
extern "C" void _s802A6234_2();
extern "C" void _s802A6234_3();
extern "C" void _s802A6234_4();
extern "C" void _s802A6234_5();
extern "C" void _s802A6234_6();
extern "C" void _s802A6234_7();
extern "C" void _s802A6234_8();
extern "C" void _s802A6234_9();
extern "C" void _s802A6234_10();
extern "C" void _s802A6234_11();
extern "C" void _s802A6234_12();
extern "C" void _s802A6234_13();
extern "C" void _s802A6234_14();
extern "C" void _s802A6234_15();
extern "C" void _s802A6234_16();
extern "C" void _s802A6234_17();
extern "C" void _s802A6234_18();
extern "C" void _s802A6234_19();
extern "C" void _s802A6234_20();
extern "C" void _s802A6234_21();
extern "C" void _s802A6234_22();
extern "C" void _s802A6234_23();
extern "C" void _s802A6234_24();
extern "C" void _s802A6234_25();
extern "C" void _s802A6234_26();
extern "C" void _s802A6234_27();
extern "C" void _s802A6234_28();
extern "C" void f_802A6234() {}
