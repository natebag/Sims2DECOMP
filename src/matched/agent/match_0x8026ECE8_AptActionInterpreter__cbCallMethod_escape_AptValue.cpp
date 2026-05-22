// 0x8026ECE8 AptActionInterpreter::cbCallMethod_escape(AptValue (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 30,-26892(13); mr 29,4; cmpwi 30,0; beq 3f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 1:; addi 31,30,12; mr 3,31; bl _s8026ECE8_0; cmpwi 3,0; bne 2f; mr 3,31; li 4,0; bl _s8026ECE8_1; 2:; mr 31,30; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s8026ECE8_2; bl _s8026ECE8_3; mr 31,3; 4:; cmpwi 29,0; beq 7f; lis 9,-32694; li 10,0; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); lwz 9,0x0(3); rlwinm 0,9,0,25,31; cmpwi 0,1; beq 5f; cmpwi 0,42; bne 6f; 5:; andis. 0,9,2048; beq 6f; li 10,1; 6:; cmpwi 10,0; beq 7f; lis 11,-32700; addi 30,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); mr 4,30; addi 9,9,1; sth 9,-6476(11); bl _s8026ECE8_4; mr 3,30; bl _s8026ECE8_5; mr 4,30; addi 3,31,12; bl _s8026ECE8_6; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026ECE8_7; 7:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8026ECE8_0();
extern "C" void _s8026ECE8_1();
extern "C" void _s8026ECE8_2();
extern "C" void _s8026ECE8_3();
extern "C" void _s8026ECE8_4();
extern "C" void _s8026ECE8_5();
extern "C" void _s8026ECE8_6();
extern "C" void _s8026ECE8_7();
extern "C" void f_8026ECE8() {}
