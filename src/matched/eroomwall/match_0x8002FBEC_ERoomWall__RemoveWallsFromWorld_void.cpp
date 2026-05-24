// 0x8002FBEC ERoomWall::RemoveWallsFromWorld(void) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,3; addi 30,1,16; addi 29,31,3; mr 4,29; mr 27,30; bl _s8002FBEC_0; mr 28,3; mr 4,31; addi 3,1,8; bl _s8002FBEC_1; addi 4,1,8; mr 3,31; bl _s8002FBEC_2; rlwinm 0,28,1,0,30; lis 5,-32696; add 0,0,28; addi 5,5,24096; addi 4,1,8; add 5,0,5; mr 3,30; bl _s8002FBEC_3; addi 3,1,8; mr 4,30; bl _s8002FBEC_4; mr 3,30; li 4,2; bl _s8002FBEC_5; mr 3,31; mr 4,29; bl _s8002FBEC_6; cmpwi 3,0; beq 2f; mr 30,29; b 1f; 0:; addi 4,1,8; mr 3,31; bl _s8002FBEC_7; rlwinm 0,28,1,0,30; lis 5,-32696; add 0,0,28; addi 5,5,24096; addi 4,1,8; add 5,0,5; mr 3,27; bl _s8002FBEC_8; mr 4,27; addi 3,1,8; bl _s8002FBEC_9; mr 3,27; li 4,2; bl _s8002FBEC_10; 1:; addi 3,1,8; mr 4,30; bl _s8002FBEC_11; cmpwi 3,0; bne 0b; mr 3,31; addi 4,1,8; bl _s8002FBEC_12; 2:; addi 3,1,8; li 4,2; bl _s8002FBEC_13; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s8002FBEC_0();
extern "C" void _s8002FBEC_1();
extern "C" void _s8002FBEC_2();
extern "C" void _s8002FBEC_3();
extern "C" void _s8002FBEC_4();
extern "C" void _s8002FBEC_5();
extern "C" void _s8002FBEC_6();
extern "C" void _s8002FBEC_7();
extern "C" void _s8002FBEC_8();
extern "C" void _s8002FBEC_9();
extern "C" void _s8002FBEC_10();
extern "C" void _s8002FBEC_11();
extern "C" void _s8002FBEC_12();
extern "C" void _s8002FBEC_13();

struct ERoomWall {
    void RemoveWallsFromWorld();
};

void ERoomWall::RemoveWallsFromWorld() {
}
