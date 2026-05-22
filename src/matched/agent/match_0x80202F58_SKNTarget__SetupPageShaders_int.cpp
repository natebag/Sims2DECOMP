// 0x80202F58 SKNTarget::SetupPageShaders(int) (1952 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; bl _s80202F58_0; addi 30,30,1; cmpwi 3,18; bgt 1f; lwz 0,0x90(31); cmpwi 0,0; bne 0f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17140; cmpwi 10,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_1; b 1f; 0:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17128; cmpwi 10,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_2; 1:; mr 4,30; mr 3,31; bl _s80202F58_3; addi 30,30,1; cmpwi 3,18; bgt 3f; lwz 0,0x90(31); cmpwi 0,0; bne 2f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17116; cmpwi 10,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_4; b 3f; 2:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17104; cmpwi 10,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_5; 3:; mr 4,30; mr 3,31; bl _s80202F58_6; addi 30,30,1; cmpwi 3,18; bgt 5f; lwz 0,0x90(31); cmpwi 0,0; bne 4f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17092; cmpwi 10,0; beq 5f; lwz 3,0x1c(31); cmpwi 3,0; beq 5f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_7; b 5f; 4:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17080; cmpwi 10,0; beq 5f; lwz 3,0x1c(31); cmpwi 3,0; beq 5f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_8; 5:; mr 4,30; mr 3,31; bl _s80202F58_9; addi 30,30,1; cmpwi 3,18; bgt 7f; lwz 0,0x90(31); cmpwi 0,0; bne 6f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17068; cmpwi 10,0; beq 7f; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_10; b 7f; 6:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17056; cmpwi 10,0; beq 7f; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_11; 7:; mr 4,30; mr 3,31; bl _s80202F58_12; addi 30,30,1; cmpwi 3,18; bgt 9f; lwz 0,0x90(31); cmpwi 0,0; bne 8f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17044; cmpwi 10,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_13; b 9f; 8:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17032; cmpwi 10,0; beq 9f; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_14; 9:; mr 4,30; mr 3,31; bl _s80202F58_15; addi 30,30,1; cmpwi 3,18; bgt 11f; lwz 0,0x90(31); cmpwi 0,0; bne 10f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17020; cmpwi 10,0; beq 11f; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_16; b 11f; 10:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-17008; cmpwi 10,0; beq 11f; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_17; 11:; mr 4,30; mr 3,31; bl _s80202F58_18; addi 30,30,1; cmpwi 3,18; bgt 13f; lwz 0,0x90(31); cmpwi 0,0; bne 12f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16996; cmpwi 10,0; beq 13f; lwz 3,0x1c(31); cmpwi 3,0; beq 13f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_19; b 13f; 12:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16984; cmpwi 10,0; beq 13f; lwz 3,0x1c(31); cmpwi 3,0; beq 13f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_20; 13:; mr 4,30; mr 3,31; bl _s80202F58_21; addi 30,30,1; cmpwi 3,18; bgt 15f; lwz 0,0x90(31); cmpwi 0,0; bne 14f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16972; cmpwi 10,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_22; b 15f; 14:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16960; cmpwi 10,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_23; 15:; mr 4,30; mr 3,31; bl _s80202F58_24; addi 30,30,1; cmpwi 3,18; bgt 17f; lwz 0,0x90(31); cmpwi 0,0; bne 16f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16948; cmpwi 10,0; beq 17f; lwz 3,0x1c(31); cmpwi 3,0; beq 17f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_25; b 17f; 16:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16936; cmpwi 10,0; beq 17f; lwz 3,0x1c(31); cmpwi 3,0; beq 17f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_26; 17:; mr 4,30; mr 3,31; bl _s80202F58_27; addi 30,30,1; cmpwi 3,18; bgt 19f; lwz 0,0x90(31); cmpwi 0,0; bne 18f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16924; cmpwi 10,0; beq 19f; lwz 3,0x1c(31); cmpwi 3,0; beq 19f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_28; b 19f; 18:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16912; cmpwi 10,0; beq 19f; lwz 3,0x1c(31); cmpwi 3,0; beq 19f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_29; 19:; mr 4,30; mr 3,31; bl _s80202F58_30; addi 30,30,1; cmpwi 3,18; bgt 21f; lwz 0,0x90(31); cmpwi 0,0; bne 20f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16900; cmpwi 10,0; beq 21f; lwz 3,0x1c(31); cmpwi 3,0; beq 21f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_31; b 21f; 20:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16884; cmpwi 10,0; beq 21f; lwz 3,0x1c(31); cmpwi 3,0; beq 21f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_32; 21:; mr 4,30; mr 3,31; bl _s80202F58_33; cmpwi 3,18; bgt 23f; lwz 0,0x90(31); cmpwi 0,0; bne 22f; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16868; cmpwi 10,0; beq 23f; lwz 3,0x1c(31); cmpwi 3,0; beq 23f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_34; b 23f; 22:; lis 9,-32700; lwz 10,0x0(31); addi 9,9,-25092; rlwinm 0,3,5,0,26; lis 11,-32704; lwzx 5,9,0; addi 4,11,-16852; cmpwi 10,0; beq 23f; lwz 3,0x1c(31); cmpwi 3,0; beq 23f; lwz 6,0x7c(31); li 7,0; bl _s80202F58_35; 23:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80202F58_0();
extern "C" void _s80202F58_1();
extern "C" void _s80202F58_2();
extern "C" void _s80202F58_3();
extern "C" void _s80202F58_4();
extern "C" void _s80202F58_5();
extern "C" void _s80202F58_6();
extern "C" void _s80202F58_7();
extern "C" void _s80202F58_8();
extern "C" void _s80202F58_9();
extern "C" void _s80202F58_10();
extern "C" void _s80202F58_11();
extern "C" void _s80202F58_12();
extern "C" void _s80202F58_13();
extern "C" void _s80202F58_14();
extern "C" void _s80202F58_15();
extern "C" void _s80202F58_16();
extern "C" void _s80202F58_17();
extern "C" void _s80202F58_18();
extern "C" void _s80202F58_19();
extern "C" void _s80202F58_20();
extern "C" void _s80202F58_21();
extern "C" void _s80202F58_22();
extern "C" void _s80202F58_23();
extern "C" void _s80202F58_24();
extern "C" void _s80202F58_25();
extern "C" void _s80202F58_26();
extern "C" void _s80202F58_27();
extern "C" void _s80202F58_28();
extern "C" void _s80202F58_29();
extern "C" void _s80202F58_30();
extern "C" void _s80202F58_31();
extern "C" void _s80202F58_32();
extern "C" void _s80202F58_33();
extern "C" void _s80202F58_34();
extern "C" void _s80202F58_35();
extern "C" void f_80202F58() {}
