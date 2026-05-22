// 0x8023362C ERLevel::AddWallInstanceToLevel(EInstance (420 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 24,3; mr 23,4; addis 31,24,3; lwz 0,-15684(31); cmpwi 0,-1; bne 0f; lwz 0,-15688(31); addi 11,31,-23880; mr 29,31; rlwinm 9,0,2,0,29; stw 0,-15684(31); stw 0,-15680(31); stwx 23,11,9; b 8f; 0:; mr 3,23; bl _s8023362C_0; cmpwi 3,0; beq 5f; mr 3,23; bl _s8023362C_1; lwz 25,0x8(3); lwz 30,-15684(31); mr 29,31; b 2f; 1:; addi 30,30,1; 2:; lwz 0,-15680(29); cmpw 30,0; bgt 6f; rlwinm 0,30,2,0,29; addi 31,29,-23880; lwzx 3,31,0; mr 27,0; bl _s8023362C_2; cmpwi 3,0; beq 1b; lwzx 3,31,27; bl _s8023362C_3; lwz 0,0x8(3); cmpw 0,25; bne 1b; lwz 0,-15680(29); cmpw 30,0; bge 6f; addi 0,27,-23880; lwz 22,0x110(23); add 26,0,29; mr 28,27; b 4f; 3:; lwz 9,0x0(26); lwz 0,0x110(9); cmpw 0,22; beq 6f; addi 26,26,4; addi 28,28,4; addi 30,30,1; 4:; lwz 0,-15680(29); cmpw 30,0; bgt 6f; addi 31,29,-23880; lwzx 3,31,27; bl _s8023362C_4; cmpwi 3,0; beq 3b; lwzx 3,31,28; bl _s8023362C_5; lwz 0,0x8(3); cmpw 0,25; beq 3b; b 6f; 5:; lwz 30,-15684(31); mr 29,31; 6:; rlwinm 0,30,2,0,29; lwz 9,-15688(29); add 11,0,24; mr 27,0; mr 3,11; rlwinm 9,9,2,0,29; addis 11,11,3; add 9,9,24; addi 4,11,-23880; addis 9,9,3; addis 11,3,3; addi 5,9,-23880; addi 3,11,-23876; cmpw 5,4; beq 7f; subf 5,4,5; bl _s8023362C_6; 7:; addi 11,29,-23880; stwx 23,11,27; lwz 9,-15680(29); addi 9,9,1; stw 9,-15680(29); 8:; lwz 9,-15688(29); addi 9,9,1; stw 9,-15688(29); lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s8023362C_0();
extern "C" void _s8023362C_1();
extern "C" void _s8023362C_2();
extern "C" void _s8023362C_3();
extern "C" void _s8023362C_4();
extern "C" void _s8023362C_5();
extern "C" void _s8023362C_6();
extern "C" void f_8023362C() {}
