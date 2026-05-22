// 0x802B68D8 AptScriptColour::objectMemberLookup(AptValue (908 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,5; lis 9,-32694; lwz 4,-10788(9); lwz 3,0x0(30); cmpw 3,4; bne 0f; li 3,0; b 1f; 0:; addi 3,3,8; addi 4,4,8; bl _s802B68D8_0; 1:; cmpwi 3,0; bne 3f; lwz 31,-26992(13); cmpwi 31,0; bne 2f; lwz 3,-23016(13); li 4,40; bl _s802B68D8_1; mr 30,3; lis 29,-32725; addi 29,29,27748; li 4,9; bl _s802B68D8_2; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B68D8_3; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-26992(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,23900; addi 5,5,23744; li 6,141; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 2:; lwz 3,-26992(13); b 16f; 3:; lis 9,-32694; lwz 3,0x0(30); lwz 4,-11056(9); cmpw 3,4; bne 4f; li 3,0; b 5f; 4:; addi 3,3,8; addi 4,4,8; bl _s802B68D8_4; 5:; cmpwi 3,0; bne 7f; lwz 31,-26988(13); cmpwi 31,0; bne 6f; lwz 3,-23016(13); li 4,40; bl _s802B68D8_5; mr 30,3; lis 29,-32725; addi 29,29,28044; li 4,9; bl _s802B68D8_6; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B68D8_7; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-26988(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,23900; addi 5,5,23744; li 6,145; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 6:; lwz 3,-26988(13); b 16f; 7:; lis 9,-32694; lwz 3,0x0(30); lwz 4,-11040(9); cmpw 3,4; bne 8f; li 3,0; b 9f; 8:; addi 3,3,8; addi 4,4,8; bl _s802B68D8_8; 9:; cmpwi 3,0; bne 11f; lwz 31,-26984(13); cmpwi 31,0; bne 10f; lwz 3,-23016(13); li 4,40; bl _s802B68D8_9; mr 30,3; lis 29,-32725; addi 29,29,28324; li 4,9; bl _s802B68D8_10; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B68D8_11; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-26984(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,23900; addi 5,5,23744; li 6,149; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 10:; lwz 3,-26984(13); b 16f; 11:; lis 9,-32694; lwz 3,0x0(30); lwz 4,-10776(9); cmpw 3,4; bne 12f; li 3,0; b 13f; 12:; addi 3,3,8; addi 4,4,8; bl _s802B68D8_12; 13:; cmpwi 3,0; bne 15f; lwz 31,-26980(13); cmpwi 31,0; bne 14f; lwz 3,-23016(13); li 4,40; bl _s802B68D8_13; mr 30,3; lis 29,-32725; addi 29,29,29952; li 4,9; bl _s802B68D8_14; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B68D8_15; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-26980(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,23900; addi 5,5,23744; li 6,153; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 14:; lwz 3,-26980(13); b 16f; 15:; li 3,0; 16:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802B68D8_0();
extern "C" void _s802B68D8_1();
extern "C" void _s802B68D8_2();
extern "C" void _s802B68D8_3();
extern "C" void _s802B68D8_4();
extern "C" void _s802B68D8_5();
extern "C" void _s802B68D8_6();
extern "C" void _s802B68D8_7();
extern "C" void _s802B68D8_8();
extern "C" void _s802B68D8_9();
extern "C" void _s802B68D8_10();
extern "C" void _s802B68D8_11();
extern "C" void _s802B68D8_12();
extern "C" void _s802B68D8_13();
extern "C" void _s802B68D8_14();
extern "C" void _s802B68D8_15();
extern "C" void f_802B68D8() {}
