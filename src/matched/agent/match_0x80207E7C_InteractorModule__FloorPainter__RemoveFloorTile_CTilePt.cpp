// 0x80207E7C InteractorModule::FloorPainter::RemoveFloorTile(CTilePt (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 25,0x7c(1); stw 0,0x9c(1); mr 26,4; mr 28,5; li 5,0; bl _s80207E7C_0; cmpwi 3,0; beq 6f; lwz 31,-21488(13); addi 3,1,8; mr 5,26; lwz 9,0x0(31); lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; addi 3,1,8; bl _s80207E7C_1; cmpwi 3,0; bne 0f; lwz 9,0x0(31); mr 4,26; lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,31,3; blrl; lis 9,-32697; rlwinm 3,3,2,0,29; lwz 11,0x5ea0(9); lwz 10,0x0(11); lwzx 9,10,3; lbz 0,0x14(9); cmpwi 0,0; beq 5f; lwzx 9,3,28; mr 4,26; li 5,0; addi 9,9,1; stwx 9,3,28; lwz 11,0x0(31); lha 3,0x90(11); lwz 0,0x94(11); add 3,31,3; mtspr 8,0; blrl; b 5f; 0:; addi 3,1,8; li 4,32; bl _s80207E7C_2; cmpwi 3,0; beq 1f; li 25,1; li 30,3; b 2f; 1:; addi 3,1,8; li 4,16; bl _s80207E7C_3; li 25,2; li 30,4; 2:; lis 9,-32697; addi 3,1,8; lwz 11,0x5ea0(9); mr 4,30; li 29,0; lwz 27,0x0(11); bl _s80207E7C_4; rlwinm 11,3,2,0,29; lwzx 9,27,11; lbz 0,0x14(9); cmpwi 0,0; beq 3f; lwzx 9,11,28; mr 5,30; addi 3,1,8; li 4,0; addi 9,9,1; li 29,1; stwx 9,11,28; bl _s80207E7C_5; 3:; addi 3,1,8; mr 4,25; bl _s80207E7C_6; rlwinm 11,3,2,0,29; lwzx 9,27,11; lbz 0,0x14(9); cmpwi 0,0; beq 4f; lwzx 9,11,28; mr 5,25; addi 3,1,8; li 4,0; addi 9,9,1; li 29,1; stwx 9,11,28; bl _s80207E7C_7; 4:; cmpwi 29,0; beq 5f; addi 30,1,64; addi 4,1,8; mr 3,30; bl _s80207E7C_8; lwz 9,0x0(31); mr 5,30; mr 4,26; lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); mr 4,26; li 5,255; lha 3,0x90(9); lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; 5:; addi 3,1,8; li 4,2; bl _s80207E7C_9; 6:; lwz 0,0x9c(1); mtspr 8,0; lmw 25,0x7c(1); addi 1,1,152"
extern "C" void _s80207E7C_0();
extern "C" void _s80207E7C_1();
extern "C" void _s80207E7C_2();
extern "C" void _s80207E7C_3();
extern "C" void _s80207E7C_4();
extern "C" void _s80207E7C_5();
extern "C" void _s80207E7C_6();
extern "C" void _s80207E7C_7();
extern "C" void _s80207E7C_8();
extern "C" void _s80207E7C_9();
extern "C" void f_80207E7C() {}
