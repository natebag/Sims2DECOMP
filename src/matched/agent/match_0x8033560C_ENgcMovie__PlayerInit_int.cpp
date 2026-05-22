// 0x8033560C ENgcMovie::PlayerInit(int) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 31,4; lis 3,-32691; li 4,0; li 5,464; addi 3,3,14656; bl _s8033560C_0; bl _s8033560C_1; lis 3,-32691; lis 4,-32691; addi 3,3,20320; addi 4,4,20352; li 5,3; bl _s8033560C_2; bl _s8033560C_3; cmpwi 3,0; bne 0f; li 3,0; b 4f; 0:; bl _s8033560C_4; li 30,1; cmpwi 3,0; bne 1f; li 30,0; 1:; li 0,0; lis 3,-32717; stw 31,-26356(13); addi 3,3,27436; stw 0,-22528(13); stw 0,-22536(13); stw 0,-22532(13); bl _s8033560C_5; cmpwi 3,0; stw 3,-26360(13); bne 2f; lwz 0,-26356(13); cmpwi 0,0; beq 2f; li 3,0; bl _s8033560C_6; mr 3,30; bl _s8033560C_7; li 3,0; b 4f; 2:; mr 3,30; bl _s8033560C_8; lwz 0,-26356(13); cmpwi 0,0; bne 3f; lis 30,-32691; li 5,1280; li 4,0; addi 3,30,20384; bl _s8033560C_9; addi 3,30,20384; li 4,1280; bl _s8033560C_10; lwz 0,-22536(13); addi 30,30,20384; li 4,640; rlwinm 3,0,2,0,29; add 3,3,0; rlwinm 3,3,7,0,24; add 3,3,30; bl _s8033560C_11; bl _s8033560C_12; 3:; li 0,1; li 3,1; stw 0,0x20(29); 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8033560C_0();
extern "C" void _s8033560C_1();
extern "C" void _s8033560C_2();
extern "C" void _s8033560C_3();
extern "C" void _s8033560C_4();
extern "C" void _s8033560C_5();
extern "C" void _s8033560C_6();
extern "C" void _s8033560C_7();
extern "C" void _s8033560C_8();
extern "C" void _s8033560C_9();
extern "C" void _s8033560C_10();
extern "C" void _s8033560C_11();
extern "C" void _s8033560C_12();
extern "C" void f_8033560C() {}
