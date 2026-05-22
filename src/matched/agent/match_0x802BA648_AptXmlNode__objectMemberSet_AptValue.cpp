// 0x802BA648 AptXmlNode::objectMemberSet(AptValue (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,4; mr 30,5; lwz 0,0x0(29); mr 31,6; rlwinm 0,0,0,25,31; cmpwi 0,32; bne 7f; lwz 3,0x0(30); lis 4,-32702; addi 4,4,-31920; addi 3,3,8; bl _s802BA648_0; cmpwi 3,0; bne 3f; lwz 9,0x0(31); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,1; beq 0f; cmpwi 0,42; bne 1f; 0:; andis. 0,9,2048; beq 1f; li 11,1; 1:; cmpwi 11,0; beq 7f; lis 11,-32700; mr 3,31; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 4,1,8; addi 9,9,1; sth 9,-6476(11); bl _s802BA648_1; lwz 11,0x24(29); cmpwi 11,0; beq 2f; lwz 9,0x0(11); lwz 4,0x8(1); lha 3,0x78(9); lwz 0,0x7c(9); addi 4,4,8; add 3,11,3; mtspr 8,0; blrl; 2:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BA648_2; b 7f; 3:; lwz 3,0x0(30); lis 4,-32702; addi 4,4,-31908; addi 3,3,8; bl _s802BA648_3; cmpwi 3,0; bne 7f; lwz 9,0x0(31); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,1; beq 4f; cmpwi 0,42; bne 5f; 4:; andis. 0,9,2048; beq 5f; li 11,1; 5:; cmpwi 11,0; beq 7f; lis 11,-32700; mr 3,31; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 4,1,8; addi 9,9,1; sth 9,-6476(11); bl _s802BA648_4; lwz 11,0x24(29); cmpwi 11,0; beq 6f; lwz 9,0x0(11); lwz 4,0x8(1); lha 3,0x90(9); lwz 0,0x94(9); addi 4,4,8; add 3,11,3; mtspr 8,0; blrl; 6:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BA648_5; 7:; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802BA648_0();
extern "C" void _s802BA648_1();
extern "C" void _s802BA648_2();
extern "C" void _s802BA648_3();
extern "C" void _s802BA648_4();
extern "C" void _s802BA648_5();
extern "C" void f_802BA648() {}
