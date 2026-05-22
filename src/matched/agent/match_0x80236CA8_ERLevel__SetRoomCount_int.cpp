// 0x80236CA8 ERLevel::SetRoomCount(int) (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,3; mr 26,4; addis 9,25,3; lwz 11,-23936(9); cmpwi 11,0; beq 2f; lwz 0,-8(11); mr 29,9; mulli 0,0,12; add 30,11,0; cmpw 11,30; beq 1f; 0:; addi 30,30,-12; mr 3,30; bl _s80236CA8_0; lwz 0,-23936(29); cmpw 0,30; bne 0b; 1:; addis 9,25,3; lwz 3,-23936(9); addi 3,3,-8; bl _s80236CA8_1; 2:; addis 9,25,3; li 31,0; lwz 3,-23932(9); mr 29,9; stw 31,-23936(9); cmpwi 3,0; beq 3f; bl _s80236CA8_2; 3:; lwz 0,-23928(29); addi 27,26,1; stw 31,-23932(29); cmpwi 0,0; beq 6f; lwz 0,-23884(29); li 31,0; addic. 9,0,1; ble 5f; mr 30,29; li 28,0; 4:; lwz 3,-23928(30); addi 31,31,1; add 3,3,28; bl _s80236CA8_3; addi 28,28,4; lwz 9,-23884(30); addi 9,9,1; cmpw 31,9; blt 4b; 5:; lwz 3,-23928(29); cmpwi 3,0; beq 6f; bl _s80236CA8_4; 6:; mulli 3,27,12; li 0,0; stw 26,-23884(29); stw 0,-23928(29); addi 3,3,8; bl _s80236CA8_5; addi 3,3,8; mr 4,26; stw 27,-8(3); mr 9,3; cmpwi 4,-1; beq 8f; li 11,1; li 0,0; 7:; stw 0,0x4(9); cmpwi 4,0; stw 0,0x0(9); addi 4,4,-1; stw 11,0x8(9); addi 9,9,12; bne 7b; 8:; rlwinm 30,27,2,0,29; stw 3,-23936(29); mr 3,30; bl _s80236CA8_6; stw 3,-23932(29); mr 3,30; bl _s80236CA8_7; stw 3,-23928(29); cmpwi 27,0; ble 10f; mtspr 9,27; mr 8,29; li 0,0; li 10,0; 9:; lwz 9,-23932(8); stwx 0,10,9; lwz 11,-23928(8); stwx 0,10,11; addi 10,10,4; bdnz 9b; 10:; mr 28,29; lwz 31,-15676(28); lwz 0,-15688(28); cmpw 31,0; bge 12f; rlwinm 29,31,2,0,29; 11:; addi 9,28,-23880; mr 3,25; lwzx 4,9,29; mr 30,28; addi 31,31,1; addi 29,29,4; bl _s80236CA8_8; lwz 0,-15688(30); cmpw 31,0; blt 11b; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80236CA8_0();
extern "C" void _s80236CA8_1();
extern "C" void _s80236CA8_2();
extern "C" void _s80236CA8_3();
extern "C" void _s80236CA8_4();
extern "C" void _s80236CA8_5();
extern "C" void _s80236CA8_6();
extern "C" void _s80236CA8_7();
extern "C" void _s80236CA8_8();
extern "C" void f_80236CA8() {}
