// 0x802B65F4 AptScriptColour::AptScriptColour(AptValue (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; li 4,26; bl _s802B65F4_0; lis 9,-32703; addi 3,30,12; addi 9,9,8984; li 4,8; stw 9,0x8(30); bl _s802B65F4_1; li 0,0; lis 9,-32703; stb 0,0x20(30); addi 9,9,24088; stw 9,0x8(30); li 11,0; lwz 0,0x20(30); rlwinm 0,0,0,10,7; stw 0,0x20(30); lwz 0,0x0(31); rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 11,0,5,31,31; 0:; cmpwi 11,0; beq 7f; mr 3,31; li 28,0; bl _s802B65F4_2; li 29,0; cmpwi 3,13; bne 1f; mr 3,31; bl _s802B65F4_3; subfic 0,3,0; adde 29,0,3; 1:; cmpwi 29,0; bne 3f; mr 3,31; li 29,0; bl _s802B65F4_4; cmpwi 3,18; bne 2f; mr 3,31; bl _s802B65F4_5; subfic 0,3,0; adde 29,0,3; 2:; cmpwi 29,0; beq 4f; 3:; li 28,1; 4:; cmpwi 28,0; bne 6f; mr 3,31; li 29,0; bl _s802B65F4_6; cmpwi 3,15; bne 5f; mr 3,31; bl _s802B65F4_7; subfic 0,3,0; adde 29,0,3; 5:; cmpwi 29,0; beq 8f; 6:; stw 31,0x24(30); lis 4,-32703; lis 5,-32703; addi 4,4,23696; lwz 9,0x8(31); addi 5,5,23744; li 6,57; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; b 8f; 7:; stw 11,0x24(30); 8:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802B65F4_0();
extern "C" void _s802B65F4_1();
extern "C" void _s802B65F4_2();
extern "C" void _s802B65F4_3();
extern "C" void _s802B65F4_4();
extern "C" void _s802B65F4_5();
extern "C" void _s802B65F4_6();
extern "C" void _s802B65F4_7();
extern "C" void f_802B65F4() {}
