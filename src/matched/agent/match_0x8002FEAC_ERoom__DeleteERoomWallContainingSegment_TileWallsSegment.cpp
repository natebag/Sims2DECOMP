// 0x8002FEAC ERoom::DeleteERoomWallContainingSegment(TileWallsSegment, (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,4; mr 7,6; beq 4f; bgt 0f; cmpwi 4,1; beq 2f; cmpwi 4,2; beq 3f; b 9f; 0:; cmpwi 4,16; beq 6f; bgt 1f; cmpwi 4,8; beq 5f; b 9f; 1:; cmpwi 4,32; beq 8f; b 9f; 2:; mr 6,5; addi 4,3,40; li 5,1; b 7f; 3:; mr 6,5; addi 4,3,28; li 5,2; b 7f; 4:; mr 6,5; addi 4,3,16; li 5,4; b 7f; 5:; mr 6,5; addi 4,3,4; li 5,8; b 7f; 6:; mr 6,5; addi 4,3,64; li 5,16; 7:; bl _s8002FEAC_0; mr. 3,3; beq 9f; bl _s8002FEAC_1; b 9f; 8:; mr 6,5; addi 4,3,88; li 5,32; bl _s8002FEAC_2; mr. 3,3; beq 9f; bl _s8002FEAC_3; 9:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8002FEAC_0();
extern "C" void _s8002FEAC_1();
extern "C" void _s8002FEAC_2();
extern "C" void _s8002FEAC_3();
extern "C" void f_8002FEAC() {}
