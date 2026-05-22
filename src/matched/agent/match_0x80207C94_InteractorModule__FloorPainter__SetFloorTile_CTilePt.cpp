// 0x80207C94 InteractorModule::FloorPainter::SetFloorTile(CTilePt (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 26,0x80(1); stw 0,0x9c(1); mr 27,3; mr 28,4; mr 30,5; mr 26,6; mr 31,7; bl _s80207C94_0; li 29,0; cmpwi 3,0; bne 0f; li 3,0; b 11f; 0:; lwz 4,-21488(13); addi 3,1,8; mr 5,28; lwz 9,0x0(4); lha 0,0xa8(9); lwz 9,0xac(9); add 4,4,0; mtspr 8,9; blrl; addi 3,1,8; bl _s80207C94_1; cmpwi 3,0; bne 2f; lwz 3,-21488(13); mr 4,28; mr 5,30; lwz 9,0x0(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; cmpw 3,30; beq 10f; cmpwi 3,0; beq 1f; rlwinm 0,3,2,0,29; lwzx 9,31,0; addi 9,9,1; stwx 9,31,0; 1:; li 29,1; b 10f; 2:; mr 3,27; mr 4,26; stw 29,0x78(1); mr 5,28; stw 29,0x7c(1); addi 6,1,8; addi 7,1,120; addi 8,1,124; bl _s80207C94_2; lwz 0,0x78(1); cmpwi 0,0; bne 3f; lwz 5,0x7c(1); b 7f; 3:; lwz 5,0x7c(1); cmpwi 5,0; bne 4f; mr 5,0; b 7f; 4:; addi 3,1,8; mr 4,30; bl _s80207C94_3; cmpw 3,30; beq 6f; cmpwi 3,0; beq 5f; rlwinm 0,3,2,0,29; lwzx 9,31,0; addi 9,9,1; stwx 9,31,0; 5:; li 29,1; 6:; lwz 5,0x78(1); 7:; addi 3,1,8; mr 4,30; bl _s80207C94_4; cmpw 3,30; beq 9f; cmpwi 3,0; beq 8f; rlwinm 0,3,2,0,29; lwzx 9,31,0; addi 9,9,1; stwx 9,31,0; 8:; li 29,1; 9:; addi 30,1,64; addi 4,1,8; mr 3,30; bl _s80207C94_5; lwz 11,-21488(13); mr 5,30; mr 4,28; lwz 9,0x0(11); lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 4,28; li 5,255; lwz 9,0x0(11); lha 3,0x90(9); lwz 0,0x94(9); add 3,11,3; mtspr 8,0; blrl; 10:; addi 3,1,8; li 4,2; bl _s80207C94_6; mr 3,29; 11:; lwz 0,0x9c(1); mtspr 8,0; lmw 26,0x80(1); addi 1,1,152"
extern "C" void _s80207C94_0();
extern "C" void _s80207C94_1();
extern "C" void _s80207C94_2();
extern "C" void _s80207C94_3();
extern "C" void _s80207C94_4();
extern "C" void _s80207C94_5();
extern "C" void _s80207C94_6();
extern "C" void f_80207C94() {}
