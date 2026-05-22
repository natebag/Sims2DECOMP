// 0x802B84CC AptScriptFunction2::SetupBeforeExecution(_AptScriptFunctionState (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 28,5; bl _s802B84CC_0; li 29,1; lwz 9,-26972(13); li 10,0; lwz 0,-26968(13); stw 9,0x4(30); rlwinm 0,0,2,0,29; stw 10,-26968(13); lwz 11,0x34(31); add 9,9,0; stw 9,-26972(13); lha 0,0xa(11); andi. 9,0,1; beq 0f; lis 4,-32694; lwz 3,0x24(31); addi 4,4,-11332; li 5,0; addi 4,4,656; li 29,2; bl _s802B84CC_1; mr 4,3; li 3,1; bl _s802B84CC_2; 0:; lwz 9,0x34(31); lha 0,0xa(9); andi. 9,0,4; beq 1f; mr 3,29; lwz 4,-22936(13); addi 29,29,1; bl _s802B84CC_3; 1:; lwz 9,0x34(31); lha 0,0xa(9); andi. 9,0,16; beq 4f; lis 9,-32694; mr 3,28; addi 9,9,-11332; li 5,0; addi 30,9,640; mr 4,30; bl _s802B84CC_4; mr. 4,3; beq 2f; lwz 0,0x0(4); andis. 9,0,2048; bne 3f; 2:; lwz 3,0x24(31); mr 4,30; li 5,0; bl _s802B84CC_5; mr 4,3; 3:; mr 3,29; addi 29,29,1; bl _s802B84CC_6; 4:; lwz 9,0x34(31); lha 0,0xa(9); andi. 9,0,64; beq 5f; addi 30,1,8; lis 4,-32703; addi 4,4,27276; mr 3,30; bl _s802B84CC_7; lwz 3,0x24(31); mr 4,30; li 5,0; bl _s802B84CC_8; mr 4,3; mr 3,29; bl _s802B84CC_9; addi 29,29,1; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B84CC_10; 5:; lwz 9,0x34(31); lha 0,0xa(9); andi. 9,0,128; beq 7f; addi 30,1,8; lis 4,-32703; addi 4,4,27284; mr 3,30; bl _s802B84CC_11; lwz 3,0x24(31); mr 4,30; li 5,0; bl _s802B84CC_12; mr. 4,3; bne 6f; lwz 4,-22936(13); 6:; mr 3,29; bl _s802B84CC_13; addi 29,29,1; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802B84CC_14; 7:; lwz 9,0x34(31); lha 0,0xa(9); andi. 9,0,256; beq 8f; lwz 4,-26996(13); mr 3,29; bl _s802B84CC_15; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802B84CC_0();
extern "C" void _s802B84CC_1();
extern "C" void _s802B84CC_2();
extern "C" void _s802B84CC_3();
extern "C" void _s802B84CC_4();
extern "C" void _s802B84CC_5();
extern "C" void _s802B84CC_6();
extern "C" void _s802B84CC_7();
extern "C" void _s802B84CC_8();
extern "C" void _s802B84CC_9();
extern "C" void _s802B84CC_10();
extern "C" void _s802B84CC_11();
extern "C" void _s802B84CC_12();
extern "C" void _s802B84CC_13();
extern "C" void _s802B84CC_14();
extern "C" void _s802B84CC_15();
extern "C" void f_802B84CC() {}
