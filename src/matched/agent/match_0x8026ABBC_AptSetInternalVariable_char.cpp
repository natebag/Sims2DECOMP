// 0x8026ABBC AptSetInternalVariable(char (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); lwz 30,-26892(13); mr 25,3; mr 26,4; cmpwi 30,0; beq 3f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 1:; addi 31,30,12; mr 3,31; bl _s8026ABBC_0; cmpwi 3,0; bne 2f; mr 3,31; li 4,0; bl _s8026ABBC_1; 2:; mr 31,30; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s8026ABBC_2; bl _s8026ABBC_3; mr 31,3; 4:; lwz 9,0x8(31); lis 28,-32704; lis 27,-32704; li 6,1396; lwz 0,0xc(9); addi 5,27,3504; lha 3,0x8(9); addi 4,28,3448; mtspr 8,0; addi 29,1,8; add 3,31,3; addi 30,31,12; blrl; addi 3,1,8; mr 4,26; bl _s8026ABBC_4; addi 4,1,8; mr 3,30; bl _s8026ABBC_5; addi 3,1,8; li 4,2; bl _s8026ABBC_6; mr 4,25; mr 3,29; bl _s8026ABBC_7; li 3,0; bl _s8026ABBC_8; mr 4,3; li 9,1; lis 3,-32694; mr 7,31; li 8,1; li 10,0; mr 6,29; li 5,0; addi 3,3,-16032; bl _s8026ABBC_9; lwz 9,0x8(31); addi 4,28,3448; addi 5,27,3504; li 6,1400; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026ABBC_10; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s8026ABBC_0();
extern "C" void _s8026ABBC_1();
extern "C" void _s8026ABBC_2();
extern "C" void _s8026ABBC_3();
extern "C" void _s8026ABBC_4();
extern "C" void _s8026ABBC_5();
extern "C" void _s8026ABBC_6();
extern "C" void _s8026ABBC_7();
extern "C" void _s8026ABBC_8();
extern "C" void _s8026ABBC_9();
extern "C" void _s8026ABBC_10();
extern "C" void f_8026ABBC() {}
