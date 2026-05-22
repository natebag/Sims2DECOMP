// 0x802B8D20 AptScriptFunction1::SetArgument(AptValue (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); lwz 0,-26960(13); mr 28,3; mr 26,4; mr 27,5; cmpwi 0,0; bne 4f; lhz 0,0x30(28); cmpwi 0,0; beq 1f; lwz 3,-23016(13); li 4,36; bl _s802B8D20_0; mr 31,3; lwz 29,0x2c(28); lhz 30,0x30(28); li 4,20; bl _s802B8D20_1; lis 9,-32703; mr 4,30; addi 9,9,8984; addi 3,31,12; stw 9,0x8(31); bl _s802B8D20_2; lis 9,-32703; stw 29,0x20(31); addi 9,9,28232; cmpwi 29,0; stw 9,0x8(31); beq 0f; lwz 9,0x8(29); lis 4,-32703; lis 5,-32703; addi 4,4,26072; lha 3,0x8(9); addi 5,5,25984; lwz 0,0xc(9); li 6,56; add 3,29,3; mtspr 8,0; blrl; 0:; stw 31,-26960(13); b 3f; 1:; lwz 3,-23016(13); li 4,36; bl _s802B8D20_3; mr 30,3; lwz 31,0x2c(28); li 4,20; bl _s802B8D20_4; lis 9,-32703; addi 3,30,12; addi 9,9,8984; li 4,4; stw 9,0x8(30); bl _s802B8D20_5; lis 9,-32703; stw 31,0x20(30); addi 9,9,28232; cmpwi 31,0; stw 9,0x8(30); beq 2f; lwz 9,0x8(31); lis 4,-32703; lis 5,-32703; addi 4,4,25936; lha 3,0x8(9); addi 5,5,25984; lwz 0,0xc(9); li 6,48; add 3,31,3; mtspr 8,0; blrl; 2:; stw 30,-26960(13); 3:; lwz 11,-26960(13); lis 4,-32703; lis 5,-32703; addi 4,4,26176; lwz 9,0x8(11); addi 5,5,26224; li 6,214; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 4:; lwz 11,0x34(28); rlwinm 10,27,2,0,29; addi 3,1,8; lwz 9,0x8(11); mr 30,3; lwzx 4,10,9; bl _s802B8D20_6; lwz 3,-26960(13); mr 4,30; mr 5,26; addi 3,3,12; bl _s802B8D20_7; mr 3,30; li 4,2; bl _s802B8D20_8; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s802B8D20_0();
extern "C" void _s802B8D20_1();
extern "C" void _s802B8D20_2();
extern "C" void _s802B8D20_3();
extern "C" void _s802B8D20_4();
extern "C" void _s802B8D20_5();
extern "C" void _s802B8D20_6();
extern "C" void _s802B8D20_7();
extern "C" void _s802B8D20_8();
extern "C" void f_802B8D20() {}
