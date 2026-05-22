// 0x8002FA34 ERoomWall::DeleteWallAtTile(CTilePt (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 26,0x88(1); stw 0,0xa4(1); mr 28,3; mr 27,4; addi 3,1,8; lwz 31,-21488(13); bl _s8002FA34_0; lwz 9,0x0(31); addi 30,1,16; mr 5,27; mr 3,30; lwz 0,0xac(9); mr 26,30; lha 4,0xa8(9); mtspr 8,0; add 4,31,4; blrl; lwz 4,0x20(28); mr 3,30; bl _s8002FA34_1; li 0,0; lwz 4,0x20(28); stw 0,0x80(1); mr 3,30; bl _s8002FA34_2; cmpwi 3,3; beq 0f; cmpwi 3,5; beq 0f; cmpwi 3,6; beq 0f; cmpwi 3,15; beq 0f; cmpwi 3,23; bne 1f; 0:; li 0,1; b 2f; 1:; li 0,0; 2:; cmpwi 0,0; bne 3f; cmpwi 3,22; bne 4f; 3:; lwz 4,0x20(28); mr 3,27; addi 5,1,128; li 6,0; bl _s8002FA34_3; cmpwi 3,0; bne 8f; 4:; lwz 0,0x20(28); cmpwi 0,16; beq 5f; cmpwi 0,32; bne 7f; 5:; lwz 9,0x0(31); mr 4,27; lha 3,0x88(9); lwz 0,0x8c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,255; bne 7f; lwz 0,0x20(28); li 4,3; cmpwi 0,16; bne 6f; li 4,4; 6:; lwz 30,0x0(31); mr 3,26; lha 29,0x90(30); addi 30,30,144; add 29,31,29; bl _s8002FA34_4; lwz 0,0x4(30); mr 5,3; mr 3,29; mr 4,27; mtspr 8,0; blrl; 7:; lwz 4,0x20(28); addi 30,1,72; mr 3,26; bl _s8002FA34_5; mr 4,26; mr 3,30; bl _s8002FA34_6; lwz 9,0x0(31); mr 5,30; mr 4,27; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,31,3; mtspr 8,0; blrl; 8:; lwz 30,0x80(1); mr 3,26; li 4,2; bl _s8002FA34_7; addi 3,1,8; li 4,2; bl _s8002FA34_8; mr 3,30; lwz 0,0xa4(1); mtspr 8,0; lmw 26,0x88(1); addi 1,1,160"
extern "C" void _s8002FA34_0();
extern "C" void _s8002FA34_1();
extern "C" void _s8002FA34_2();
extern "C" void _s8002FA34_3();
extern "C" void _s8002FA34_4();
extern "C" void _s8002FA34_5();
extern "C" void _s8002FA34_6();
extern "C" void _s8002FA34_7();
extern "C" void _s8002FA34_8();
extern "C" void f_8002FA34() {}
