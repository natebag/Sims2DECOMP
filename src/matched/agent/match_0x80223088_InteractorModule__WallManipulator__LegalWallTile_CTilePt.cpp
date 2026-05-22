// 0x80223088 InteractorModule::WallManipulator::LegalWallTile(CTilePt (716 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 29,4; lwz 31,-21488(13); mr. 30,5; bne 0f; lwz 9,0x0(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 11f; lwz 9,0x0(31); mr 4,29; lha 3,0x128(9); lwz 0,0x12c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,1; bne 17f; b 11f; 0:; addi 3,1,8; mr 4,29; bl _s80223088_0; mr 3,30; addi 4,1,8; bl _s80223088_1; lwz 9,0x0(31); mr 4,29; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 10f; lwz 9,0x0(31); addi 4,1,8; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 10f; lwz 9,0x0(31); mr 4,29; lha 3,0x128(9); lwz 0,0x12c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 10f; lwz 9,0x0(31); addi 4,1,8; lha 3,0x128(9); lwz 0,0x12c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 10f; li 30,0; 1:; cmpwi 30,0; mr 4,29; beq 2f; addi 4,1,8; 2:; addi 3,1,16; li 5,0; bl _s80223088_2; lwz 0,0x14(1); cmpwi 0,0; beq 15f; li 27,0; 3:; lwz 31,0x14(1); li 4,34; lwz 9,0x4(31); lha 3,0x260(9); lwz 0,0x264(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 14f; lwz 9,0x4(31); lha 3,0x318(9); lwz 0,0x31c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,2; bne 6f; cmpwi 31,0; beq 4f; lwz 3,0x0(31); li 4,7; bl _s80223088_3; b 5f; 4:; li 3,0; 5:; bl _s80223088_4; mr. 3,3; beq 10f; stw 27,0x7c(3); b 10f; 6:; lwz 9,0x4(31); li 4,62; lha 3,0x260(9); lwz 0,0x264(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bgt 10f; cmpwi 31,0; beq 7f; lwz 3,0x0(31); li 4,3; bl _s80223088_5; mr 31,3; b 8f; 7:; li 31,0; 8:; cmpwi 31,0; beq 14f; lwz 9,0x4(31); lha 3,0x10(9); lwz 0,0x14(9); b 13f; 9:; lwz 3,0x0(31); li 4,62; lwz 9,0x4(3); lha 0,0x260(9); lwz 9,0x264(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; ble 12f; 10:; addi 3,1,8; li 4,2; bl _s80223088_6; 11:; li 3,0; b 17f; 12:; lwz 9,0x4(31); lha 3,0x18(9); lwz 0,0x1c(9); 13:; add 3,31,3; mtspr 8,0; blrl; mr. 31,3; bne 9b; 14:; addi 3,1,16; bl _s80223088_7; lwz 0,0x14(1); cmpwi 0,0; bne 3b; 15:; addi 3,1,8; mr 4,29; bl _s80223088_8; cmpwi 3,0; bne 16f; addi 30,30,1; cmpwi 30,1; ble 1b; 16:; addi 3,1,8; li 4,2; bl _s80223088_9; li 3,1; 17:; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s80223088_0();
extern "C" void _s80223088_1();
extern "C" void _s80223088_2();
extern "C" void _s80223088_3();
extern "C" void _s80223088_4();
extern "C" void _s80223088_5();
extern "C" void _s80223088_6();
extern "C" void _s80223088_7();
extern "C" void _s80223088_8();
extern "C" void _s80223088_9();
extern "C" void f_80223088() {}
