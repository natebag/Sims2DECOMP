// 0x80207AE0 InteractorModule::FloorPainter::SetFloorTile(CTilePt (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 26,0x78(1); stw 0,0x94(1); mr 28,4; mr 30,5; mr 29,6; li 26,0; bl _s80207AE0_0; cmpwi 3,0; beq 9f; lwz 31,-21488(13); addi 3,1,8; mr 5,28; lwz 9,0x0(31); lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; addi 3,1,8; bl _s80207AE0_1; cmpwi 3,0; bne 1f; lwz 9,0x0(31); mr 4,28; mr 5,30; lha 3,0x90(9); lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; cmpw 3,30; beq 8f; cmpwi 3,0; beq 0f; rlwinm 0,3,2,0,29; lwzx 9,29,0; addi 9,9,1; stwx 9,29,0; 0:; li 26,1; b 8f; 1:; addi 3,1,8; li 4,32; bl _s80207AE0_2; cmpwi 3,0; beq 2f; li 27,1; li 5,3; b 3f; 2:; addi 3,1,8; li 4,16; bl _s80207AE0_3; li 27,2; li 5,4; 3:; addi 3,1,8; mr 4,30; bl _s80207AE0_4; cmpw 3,30; beq 5f; cmpwi 3,0; beq 4f; rlwinm 0,3,2,0,29; lwzx 9,29,0; addi 9,9,1; stwx 9,29,0; 4:; li 26,1; 5:; mr 5,27; addi 3,1,8; mr 4,30; bl _s80207AE0_5; cmpw 3,30; beq 7f; cmpwi 3,0; beq 6f; rlwinm 0,3,2,0,29; lwzx 9,29,0; addi 9,9,1; stwx 9,29,0; 6:; li 26,1; 7:; addi 30,1,64; addi 4,1,8; mr 3,30; bl _s80207AE0_6; lwz 9,0x0(31); mr 5,30; mr 4,28; lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); mr 4,28; li 5,255; lha 3,0x90(9); lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; 8:; addi 3,1,8; li 4,2; bl _s80207AE0_7; 9:; mr 3,26; lwz 0,0x94(1); mtspr 8,0; lmw 26,0x78(1); addi 1,1,144"
extern "C" void _s80207AE0_0();
extern "C" void _s80207AE0_1();
extern "C" void _s80207AE0_2();
extern "C" void _s80207AE0_3();
extern "C" void _s80207AE0_4();
extern "C" void _s80207AE0_5();
extern "C" void _s80207AE0_6();
extern "C" void _s80207AE0_7();
extern "C" void f_80207AE0() {}
