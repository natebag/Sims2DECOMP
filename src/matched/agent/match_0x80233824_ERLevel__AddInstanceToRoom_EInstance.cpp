// 0x80233824 ERLevel::AddInstanceToRoom(EInstance (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; bl _s80233824_0; lwz 0,0x5c(31); stw 3,0x54(31); andis. 9,0,1; beq 0f; addis 9,30,3; rlwinm 10,3,2,0,29; lwz 11,-23932(9); li 0,0; stwx 31,10,11; stw 0,0x78(31); b 2f; 0:; andis. 9,0,2; beq 1f; mulli 3,3,12; addis 9,30,3; lwz 0,-23936(9); mr 4,31; add 3,3,0; bl _s80233824_1; stw 3,0x78(31); 1:; lwz 0,0x5c(31); andi. 9,0,32768; beq 2f; lwz 9,0x0(31); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80233824_0();
extern "C" void _s80233824_1();
extern "C" void f_80233824() {}
