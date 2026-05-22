// 0x802B34B8 AptValue::urlEncodeCustomRender(void) (676 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); lis 31,-32700; mr 27,3; lhz 9,-6476(31); addi 30,31,-6476; stw 30,0x8(1); addi 9,9,1; sth 9,-6476(31); lwz 0,0x0(4); andis. 9,0,2048; bne 0f; stw 30,0x0(27); lhz 0,-6476(31); mr 9,0; sth 0,-6476(31); cmpwi 9,0; bne 11f; lhz 5,0x4(30); mr 4,30; b 1f; 0:; lwz 9,0x8(4); lha 3,0x20(9); lwz 0,0x24(9); add 3,4,3; mtspr 8,0; blrl; mr. 28,3; bne 2f; lwz 11,0x8(1); stw 11,0x0(27); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); 1:; lwz 3,-23020(13); addi 5,5,9; bl _s802B34B8_0; b 11f; 2:; lhz 9,-6476(31); mr 3,28; stw 30,0x10(1); lis 26,-32703; addi 9,9,1; sth 9,-6476(31); bl _s802B34B8_1; mr. 30,3; beq 9f; addi 29,1,16; 3:; lwz 9,0x0(30); stw 9,0x18(1); lhz 11,0x0(9); addi 11,11,1; sth 11,0x0(9); lwz 3,0x18(1); lbz 0,0x8(3); cmpwi 0,95; bne 7f; addi 31,3,9; lis 4,-32703; addi 4,4,8416; mr 3,31; bl _s802B34B8_2; cmpwi 3,0; beq 4f; lis 4,-32703; mr 3,31; addi 4,4,8428; bl _s802B34B8_3; cmpwi 3,0; bne 5f; 4:; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B34B8_4; b 8f; 5:; lwz 3,0x4(30); li 11,0; lwz 9,0x0(3); rlwinm 0,9,0,25,31; cmpwi 0,9; bne 6f; rlwinm 11,9,5,31,31; 6:; cmpwi 11,0; bne 7f; mr 4,29; bl _s802B34B8_5; addi 4,1,24; addi 3,1,8; bl _s802B34B8_6; lis 4,-32703; addi 3,1,8; addi 4,4,8408; bl _s802B34B8_7; mr 4,29; addi 3,1,8; bl _s802B34B8_8; addi 3,1,8; addi 4,26,8412; bl _s802B34B8_9; 7:; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B34B8_10; 8:; mr 4,30; mr 3,28; bl _s802B34B8_11; mr. 30,3; bne 3b; 9:; lis 4,-32703; addi 3,1,8; addi 4,4,8412; bl _s802B34B8_12; lwz 11,0x8(1); stw 11,0x0(27); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 10f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B34B8_13; 10:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B34B8_14; 11:; mr 3,27; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"
extern "C" void _s802B34B8_0();
extern "C" void _s802B34B8_1();
extern "C" void _s802B34B8_2();
extern "C" void _s802B34B8_3();
extern "C" void _s802B34B8_4();
extern "C" void _s802B34B8_5();
extern "C" void _s802B34B8_6();
extern "C" void _s802B34B8_7();
extern "C" void _s802B34B8_8();
extern "C" void _s802B34B8_9();
extern "C" void _s802B34B8_10();
extern "C" void _s802B34B8_11();
extern "C" void _s802B34B8_12();
extern "C" void _s802B34B8_13();
extern "C" void _s802B34B8_14();
extern "C" void f_802B34B8() {}
