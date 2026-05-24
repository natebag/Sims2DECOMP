// 0x8002F84C ERoomWall::HasSegment(TileWallsSegment, (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 31,3; mr 27,5; lwz 0,0x20(31); mr 26,6; cmpw 0,4; bne 8f; addi 4,31,3; mr 3,31; mr 25,4; bl _s8002F84C_0; cmpwi 3,0; beq 0f; mr 3,27; mr 4,26; bl _s8002F84C_1; cmpwi 3,0; beq 0f; mr 3,27; mr 4,31; bl _s8002F84C_2; cmpwi 3,0; beq 0f; li 3,1; b 9f; 0:; mr 4,25; mr 3,31; bl _s8002F84C_3; li 28,0; mr 29,3; addi 30,1,16; mr 4,31; addi 3,1,8; bl _s8002F84C_4; li 31,0; rlwinm 0,29,1,0,30; lis 5,-32696; add 0,0,29; addi 5,5,24096; addi 4,1,8; add 5,0,5; mr 3,30; bl _s8002F84C_5; mr 4,30; addi 3,1,8; bl _s8002F84C_6; mr 3,30; li 4,2; bl _s8002F84C_7; b 4f; 1:; cmpwi 31,0; bne 2f; addi 3,1,8; mr 4,27; bl _s8002F84C_8; cmpwi 3,0; beq 2f; li 31,1; 2:; cmpwi 28,0; bne 3f; addi 3,1,8; mr 4,26; bl _s8002F84C_9; cmpwi 3,0; beq 3f; li 28,1; 3:; rlwinm 0,29,1,0,30; lis 5,-32696; add 0,0,29; addi 5,5,24096; addi 4,1,8; add 5,0,5; mr 3,30; bl _s8002F84C_10; mr 4,30; addi 3,1,8; bl _s8002F84C_11; mr 3,30; li 4,2; bl _s8002F84C_12; 4:; addi 3,1,8; mr 4,25; bl _s8002F84C_13; cmpwi 3,0; bne 1b; cmpwi 31,0; bne 5f; mr 4,27; addi 3,1,8; bl _s8002F84C_14; cmpwi 3,0; beq 5f; li 31,1; 5:; cmpwi 28,0; bne 6f; mr 4,26; addi 3,1,8; bl _s8002F84C_15; cmpwi 3,0; beq 6f; li 28,1; 6:; cmpwi 31,0; beq 7f; cmpwi 28,0; beq 7f; addi 3,1,8; li 4,2; bl _s8002F84C_16; li 3,1; b 9f; 7:; addi 3,1,8; li 4,2; bl _s8002F84C_17; 8:; li 3,0; 9:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s8002F84C_0();
extern "C" void _s8002F84C_1();
extern "C" void _s8002F84C_2();
extern "C" void _s8002F84C_3();
extern "C" void _s8002F84C_4();
extern "C" void _s8002F84C_5();
extern "C" void _s8002F84C_6();
extern "C" void _s8002F84C_7();
extern "C" void _s8002F84C_8();
extern "C" void _s8002F84C_9();
extern "C" void _s8002F84C_10();
extern "C" void _s8002F84C_11();
extern "C" void _s8002F84C_12();
extern "C" void _s8002F84C_13();
extern "C" void _s8002F84C_14();
extern "C" void _s8002F84C_15();
extern "C" void _s8002F84C_16();
extern "C" void _s8002F84C_17();

struct ERoomWall {
    void HasSegment_TileWallsSegment();
};

void ERoomWall::HasSegment_TileWallsSegment() {
}
