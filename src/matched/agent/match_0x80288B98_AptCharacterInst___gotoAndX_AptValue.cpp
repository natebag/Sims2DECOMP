// 0x80288B98 AptCharacterInst::_gotoAndX(AptValue (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 28,5; cmpwi 4,0; ble 7f; lis 9,-32694; cmpwi 29,0; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 31,-4(11); beq 7f; mr 3,29; li 30,0; bl _s80288B98_0; cmpwi 3,19; bne 0f; mr 3,29; bl _s80288B98_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 7f; lwz 0,0x0(31); li 9,0; mr 11,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 1f; cmpwi 0,42; bne 2f; 1:; andis. 0,11,2048; beq 2f; li 9,1; 2:; cmpwi 9,0; beq 4f; lwz 9,0x4c(29); rlwinm 0,11,0,25,31; cmpwi 0,1; mr 4,31; lwz 3,0x8(9); beq 3f; lwz 4,0x24(31); 3:; addi 3,3,8; addi 4,4,12; bl _s80288B98_2; addi 3,3,1; b 5f; 4:; mr 3,31; bl _s80288B98_3; 5:; addic. 4,3,-1; blt 7f; mr 3,29; bl _s80288B98_4; lwz 3,0x4c(29); cmpwi 28,0; li 9,1; bne 6f; li 9,0; 6:; lwz 0,0x1c(3); rlwimi 0,9,6,25,25; stw 0,0x1c(3); 7:; lwz 3,-22936(13); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80288B98_0();
extern "C" void _s80288B98_1();
extern "C" void _s80288B98_2();
extern "C" void _s80288B98_3();
extern "C" void _s80288B98_4();
extern "C" void f_80288B98() {}
