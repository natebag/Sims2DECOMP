// 0x802BB4E4 AptXmlNode::sMethod_toString(AptValue (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,3; lwz 0,0x0(29); rlwinm 0,0,0,25,31; cmpwi 0,32; beq 0f; lwz 3,-22936(13); b 6f; 0:; lwz 31,-26892(13); cmpwi 31,0; beq 3f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 2:; addi 30,31,12; mr 3,30; bl _s802BB4E4_0; cmpwi 3,0; bne 4f; mr 3,30; li 4,0; bl _s802BB4E4_1; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s802BB4E4_2; bl _s802BB4E4_3; mr 31,3; 4:; lis 9,-32694; addi 3,1,8; lwz 4,-10940(9); addi 30,31,12; addi 4,4,8; bl _s802BB4E4_4; addi 4,1,8; mr 3,30; bl _s802BB4E4_5; addi 3,1,8; li 4,2; bl _s802BB4E4_6; lwz 11,0x24(29); cmpwi 11,0; beq 5f; lwz 9,0x0(11); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 5f; mr 4,3; addi 3,1,8; bl _s802BB4E4_7; addi 4,1,8; mr 3,30; bl _s802BB4E4_8; addi 3,1,8; li 4,2; bl _s802BB4E4_9; 5:; mr 3,31; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802BB4E4_0();
extern "C" void _s802BB4E4_1();
extern "C" void _s802BB4E4_2();
extern "C" void _s802BB4E4_3();
extern "C" void _s802BB4E4_4();
extern "C" void _s802BB4E4_5();
extern "C" void _s802BB4E4_6();
extern "C" void _s802BB4E4_7();
extern "C" void _s802BB4E4_8();
extern "C" void _s802BB4E4_9();
extern "C" void f_802BB4E4() {}
