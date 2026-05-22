// 0x801FE304 PDATarget::HandleSubTargetStateChange(int, (948 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 29,3; mr 26,4; rlwinm 31,26,2,0,29; addi 30,29,268; lwzx 11,30,31; mr 28,5; cmpwi 11,0; beq 0f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,30,31; 0:; addi 9,29,308; lwzx 11,9,31; mr 21,9; cmpwi 11,0; beq 1f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,21,31; 1:; addi 9,29,276; lwzx 11,9,31; mr 22,9; cmpwi 11,0; beq 2f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,22,31; 2:; addi 9,29,300; lwzx 11,9,31; mr 23,9; cmpwi 11,0; beq 3f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,23,31; 3:; addi 24,29,324; lwzx 11,24,31; mr 30,24; cmpwi 11,0; beq 4f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,30,31; 4:; addi 25,29,292; lwzx 11,25,31; mr 30,25; cmpwi 11,0; beq 5f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,30,31; 5:; addi 27,29,316; lwzx 11,27,31; mr 30,27; cmpwi 11,0; beq 6f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,30,31; 6:; addi 30,29,284; lwzx 11,30,31; cmpwi 11,0; beq 7f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stwx 0,30,31; 7:; mr 3,29; mr 4,26; li 5,10; bl _s801FE304_0; cmpwi 28,5; beq 15f; bgt 9f; cmpwi 28,2; beq 12f; bgt 8f; cmpwi 28,1; beq 11f; b 20f; 8:; cmpwi 28,3; beq 13f; cmpwi 28,4; beq 14f; b 20f; 9:; cmpwi 28,8; beq 17f; bgt 10f; cmpwi 28,6; beq 20f; cmpwi 28,7; beq 16f; b 20f; 10:; cmpwi 28,9; beq 18f; b 20f; 11:; addi 30,29,268; lwzx 0,30,31; cmpwi 0,0; bne 20f; li 3,164; bl _s801FE304_1; mr 4,26; bl _s801FE304_2; b 19f; 12:; lwzx 0,21,31; cmpwi 0,0; bne 20f; li 3,13040; bl _s801FE304_3; mr 4,26; bl _s801FE304_4; stwx 3,21,31; b 20f; 13:; lwzx 0,22,31; cmpwi 0,0; bne 20f; li 3,164; bl _s801FE304_5; mr 4,26; bl _s801FE304_6; stwx 3,22,31; b 20f; 14:; lwzx 0,23,31; cmpwi 0,0; bne 20f; li 3,160; bl _s801FE304_7; mr 4,26; bl _s801FE304_8; stwx 3,23,31; b 20f; 15:; lwzx 0,24,31; cmpwi 0,0; bne 20f; lwz 0,0x144(29); cmpwi 0,0; bne 20f; lwz 0,0x148(29); cmpwi 0,0; bne 20f; li 3,160; bl _s801FE304_9; mr 4,26; bl _s801FE304_10; stwx 3,24,31; b 20f; 16:; lwzx 0,25,31; cmpwi 0,0; bne 20f; li 3,152; bl _s801FE304_11; mr 4,26; bl _s801FE304_12; stwx 3,25,31; b 20f; 17:; lwzx 0,27,31; cmpwi 0,0; bne 20f; lwz 0,0x13c(29); cmpwi 0,0; bne 20f; lwz 0,0x140(29); cmpwi 0,0; bne 20f; li 3,228; bl _s801FE304_13; mr 4,26; bl _s801FE304_14; stwx 3,27,31; b 20f; 18:; lwzx 0,30,31; cmpwi 0,0; bne 20f; li 3,148; bl _s801FE304_15; mr 4,26; bl _s801FE304_16; 19:; stwx 3,30,31; 20:; mr 3,29; bl _s801FE304_17; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s801FE304_0();
extern "C" void _s801FE304_1();
extern "C" void _s801FE304_2();
extern "C" void _s801FE304_3();
extern "C" void _s801FE304_4();
extern "C" void _s801FE304_5();
extern "C" void _s801FE304_6();
extern "C" void _s801FE304_7();
extern "C" void _s801FE304_8();
extern "C" void _s801FE304_9();
extern "C" void _s801FE304_10();
extern "C" void _s801FE304_11();
extern "C" void _s801FE304_12();
extern "C" void _s801FE304_13();
extern "C" void _s801FE304_14();
extern "C" void _s801FE304_15();
extern "C" void _s801FE304_16();
extern "C" void _s801FE304_17();
extern "C" void f_801FE304() {}
