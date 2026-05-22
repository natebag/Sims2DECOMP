// 0x8023353C ERLevel::AddInstanceToLevelHead(EInstance (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; bl _s8023353C_0; stw 30,0x4(31); mr 3,30; mr 4,31; bl _s8023353C_1; lwz 0,0x5c(31); andis. 9,0,4; beq 0f; addis 3,30,3; mr 4,31; addi 3,3,-23900; bl _s8023353C_2; stw 3,0x78(31); b 3f; 0:; andis. 9,0,1; bne 3f; addis 9,30,3; lwz 11,-15688(9); mr 10,9; cmpwi 11,0; ble 2f; rlwinm 9,11,2,0,29; addi 9,9,-23880; add 9,9,10; 1:; lwz 0,-4(9); addic. 11,11,-1; stw 0,0x0(9); addi 9,9,-4; bgt 1b; 2:; lwz 9,-15688(10); stw 31,-23880(10); addi 9,9,1; stw 9,-15688(10); 3:; lwz 0,0x5c(31); andi. 9,0,256; beq 4f; lwz 9,0x0(31); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,31,3; mtspr 8,0; blrl; mr 4,3; mr 5,31; addis 3,30,3; li 6,1; addi 3,3,-23948; bl _s8023353C_3; stw 3,0x34(31); 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023353C_0();
extern "C" void _s8023353C_1();
extern "C" void _s8023353C_2();
extern "C" void _s8023353C_3();
extern "C" void f_8023353C() {}
