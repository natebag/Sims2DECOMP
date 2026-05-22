// 0x802A80D4 AptError::objectMemberSet(AptValue (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,5; mr 29,3; lwz 3,0x0(30); lis 4,-32703; mr 31,6; addi 4,4,-20808; addi 3,3,8; bl _s802A80D4_0; cmpwi 3,0; bne 0f; lis 11,-32700; addi 30,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); mr 3,31; addi 9,9,1; mr 4,30; sth 9,-6476(11); bl _s802A80D4_1; mr 4,30; addi 3,29,36; b 1f; 0:; lwz 3,0x0(30); lis 4,-32703; addi 4,4,-20800; addi 3,3,8; bl _s802A80D4_2; cmpwi 3,0; bne 3f; lis 11,-32700; addi 30,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); mr 3,31; addi 9,9,1; mr 4,30; sth 9,-6476(11); bl _s802A80D4_3; mr 4,30; addi 3,29,40; 1:; bl _s802A80D4_4; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A80D4_5; 2:; li 3,1; b 4f; 3:; li 3,0; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802A80D4_0();
extern "C" void _s802A80D4_1();
extern "C" void _s802A80D4_2();
extern "C" void _s802A80D4_3();
extern "C" void _s802A80D4_4();
extern "C" void _s802A80D4_5();
extern "C" void f_802A80D4() {}
