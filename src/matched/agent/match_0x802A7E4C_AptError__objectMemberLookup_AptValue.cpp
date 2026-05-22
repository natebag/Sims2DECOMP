// 0x802A7E4C AptError::objectMemberLookup(AptValue (648 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,5; mr 31,3; lwz 3,0x0(30); lis 4,-32703; addi 4,4,-20808; addi 3,3,8; bl _s802A7E4C_0; cmpwi 3,0; bne 5f; lwz 30,-26892(13); cmpwi 30,0; beq 3f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 1:; addi 29,30,12; mr 3,29; bl _s802A7E4C_1; cmpwi 3,0; bne 2f; mr 3,29; li 4,0; bl _s802A7E4C_2; 2:; mr 29,30; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s802A7E4C_3; bl _s802A7E4C_4; mr 29,3; 4:; lwz 4,0x24(31); b 11f; 5:; lwz 3,0x0(30); lis 4,-32703; addi 4,4,-20800; addi 3,3,8; bl _s802A7E4C_5; cmpwi 3,0; bne 12f; lwz 30,-26892(13); cmpwi 30,0; beq 9f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 6f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 7f; 6:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 7:; addi 29,30,12; mr 3,29; bl _s802A7E4C_6; cmpwi 3,0; bne 8f; mr 3,29; li 4,0; bl _s802A7E4C_7; 8:; mr 29,30; b 10f; 9:; lwz 3,-23020(13); li 4,20; bl _s802A7E4C_8; bl _s802A7E4C_9; mr 29,3; 10:; lwz 4,0x28(31); 11:; addi 3,1,8; addi 30,29,12; addi 4,4,8; bl _s802A7E4C_10; addi 4,1,8; mr 3,30; bl _s802A7E4C_11; addi 3,1,8; li 4,2; bl _s802A7E4C_12; mr 3,29; b 15f; 12:; lwz 3,0x0(30); lis 4,-32703; addi 4,4,-22004; addi 3,3,8; bl _s802A7E4C_13; cmpwi 3,0; bne 14f; lwz 31,-27112(13); cmpwi 31,0; bne 13f; lwz 3,-23016(13); li 4,40; bl _s802A7E4C_14; mr 30,3; lis 29,-32725; addi 29,29,-32084; li 4,9; bl _s802A7E4C_15; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802A7E4C_16; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-27112(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,-20792; addi 5,5,-21544; li 6,1263; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 13:; lwz 3,-27112(13); b 15f; 14:; li 3,0; 15:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802A7E4C_0();
extern "C" void _s802A7E4C_1();
extern "C" void _s802A7E4C_2();
extern "C" void _s802A7E4C_3();
extern "C" void _s802A7E4C_4();
extern "C" void _s802A7E4C_5();
extern "C" void _s802A7E4C_6();
extern "C" void _s802A7E4C_7();
extern "C" void _s802A7E4C_8();
extern "C" void _s802A7E4C_9();
extern "C" void _s802A7E4C_10();
extern "C" void _s802A7E4C_11();
extern "C" void _s802A7E4C_12();
extern "C" void _s802A7E4C_13();
extern "C" void _s802A7E4C_14();
extern "C" void _s802A7E4C_15();
extern "C" void _s802A7E4C_16();
extern "C" void f_802A7E4C() {}
