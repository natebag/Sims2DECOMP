// 0x801FDFA4 PDATarget::HandleSubTargetStateChange(FlowGotoTarget::eFlashState) (864 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 27,3; li 31,0; addi 22,27,276; mr 29,4; lwzx 11,22,31; cmpwi 11,0; beq 0f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 31,22,31; 0:; lwz 11,0x134(27); addi 21,27,308; mr 31,21; li 30,0; cmpwi 11,0; beq 1f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 30,31,30; 1:; addi 24,27,316; li 31,0; lwzx 11,24,31; mr 30,24; cmpwi 11,0; beq 2f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 31,30,31; 2:; addi 9,27,268; lwzx 11,9,31; mr 23,9; cmpwi 11,0; beq 3f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 31,23,31; 3:; addi 25,27,284; lwzx 11,25,31; mr 30,25; cmpwi 11,0; beq 4f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 31,30,31; 4:; addi 26,27,292; lwzx 11,26,31; mr 30,26; cmpwi 11,0; beq 5f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 31,30,31; 5:; addi 28,27,300; lwzx 11,28,31; mr 30,28; cmpwi 11,0; beq 6f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 31,30,31; 6:; addi 30,27,324; lwzx 11,30,31; cmpwi 11,0; beq 7f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stwx 31,30,31; 7:; cmpwi 29,18; bne 8f; lwzx 0,21,31; cmpwi 0,0; bne 15f; li 3,13040; bl _s801FDFA4_0; li 4,0; bl _s801FDFA4_1; stwx 3,21,31; b 15f; 8:; cmpwi 29,12; bne 9f; lwzx 0,22,31; cmpwi 0,0; bne 15f; li 3,164; bl _s801FDFA4_2; li 4,0; bl _s801FDFA4_3; stwx 3,22,31; b 15f; 9:; cmpwi 29,13; beq 15f; cmpwi 29,14; bne 10f; lwzx 0,24,31; cmpwi 0,0; bne 15f; lwz 0,0x13c(27); cmpwi 0,0; bne 15f; lwz 0,0x140(27); cmpwi 0,0; bne 15f; bl _s801FDFA4_4; cmpwi 3,0; beq 15f; li 3,228; bl _s801FDFA4_5; li 4,0; bl _s801FDFA4_6; stwx 3,24,31; b 15f; 10:; cmpwi 29,15; bne 11f; lwzx 0,26,31; cmpwi 0,0; bne 15f; li 3,152; bl _s801FDFA4_7; li 4,0; bl _s801FDFA4_8; stwx 3,26,31; b 15f; 11:; cmpwi 29,16; bne 12f; lwzx 0,25,31; cmpwi 0,0; bne 15f; li 3,148; bl _s801FDFA4_9; li 4,0; bl _s801FDFA4_10; stwx 3,25,31; b 15f; 12:; cmpwi 29,17; bne 13f; lwzx 0,30,31; cmpwi 0,0; bne 15f; li 3,160; bl _s801FDFA4_11; li 4,0; bl _s801FDFA4_12; stwx 3,30,31; b 15f; 13:; cmpwi 29,19; bne 14f; lwzx 0,23,31; cmpwi 0,0; bne 15f; li 3,164; bl _s801FDFA4_13; li 4,0; bl _s801FDFA4_14; stwx 3,23,31; b 15f; 14:; cmpwi 29,20; bne 15f; lwzx 0,28,31; cmpwi 0,0; bne 15f; li 3,160; bl _s801FDFA4_15; li 4,0; bl _s801FDFA4_16; stwx 3,28,31; 15:; mr 3,27; bl _s801FDFA4_17; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s801FDFA4_0();
extern "C" void _s801FDFA4_1();
extern "C" void _s801FDFA4_2();
extern "C" void _s801FDFA4_3();
extern "C" void _s801FDFA4_4();
extern "C" void _s801FDFA4_5();
extern "C" void _s801FDFA4_6();
extern "C" void _s801FDFA4_7();
extern "C" void _s801FDFA4_8();
extern "C" void _s801FDFA4_9();
extern "C" void _s801FDFA4_10();
extern "C" void _s801FDFA4_11();
extern "C" void _s801FDFA4_12();
extern "C" void _s801FDFA4_13();
extern "C" void _s801FDFA4_14();
extern "C" void _s801FDFA4_15();
extern "C" void _s801FDFA4_16();
extern "C" void _s801FDFA4_17();
extern "C" void f_801FDFA4() {}
