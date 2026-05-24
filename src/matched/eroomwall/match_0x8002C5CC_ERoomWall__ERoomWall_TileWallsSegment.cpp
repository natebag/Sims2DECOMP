// 0x8002C5CC ERoomWall::ERoomWall(TileWallsSegment, (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 25,0x54(1); stw 0,0x74(1); lis 9,-32698; mr 31,3; addi 9,9,-20592; mr 27,6; mr 25,7; mr 26,4; mr 28,5; stw 9,0x3c(31); addi 29,31,3; bl _s8002C5CC_0; li 30,0; mr 3,29; bl _s8002C5CC_1; addi 9,31,20; li 0,1; stw 30,0x4(9); addi 3,1,8; stw 30,0x14(31); mr 5,27; lwz 11,-21488(13); stw 0,0x8(9); lwz 9,0x0(11); lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,11,4; blrl; mr 4,27; mr 3,31; bl _s8002C5CC_2; mr 4,27; mr 3,29; bl _s8002C5CC_3; lis 9,-32707; stw 30,0x30(31); lfs f0,0xddc(9); mr 4,31; stw 26,0x20(31); stfs f0,0x38(31); stw 28,0x24(31); stw 30,0x2c(31); stfs f0,0x34(31); lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; lwz 9,-21472(13); ori 0,0,65531; cmpw 3,0; bne 5f; mr 3,9; mr 4,31; addi 5,1,64; addi 6,1,68; addi 7,1,72; addi 8,1,76; bl _s8002C5CC_4; cmpwi 28,1; bne 0f; lwz 0,0x48(1); cmpwi 0,1; bne 3f; lwz 9,0x40(1); b 4f; 0:; cmpwi 28,3; bne 1f; lwz 0,0x48(1); cmpwi 0,3; bne 3f; lwz 9,0x40(1); b 4f; 1:; cmpwi 28,2; bne 2f; lwz 0,0x48(1); cmpwi 0,4; bne 3f; lwz 9,0x40(1); b 4f; 2:; cmpwi 28,4; bne 6f; lwz 0,0x48(1); cmpwi 0,2; bne 3f; lwz 9,0x40(1); b 4f; 3:; lwz 9,0x44(1); 4:; lhz 9,0x0(9); sth 9,0x28(31); b 6f; 5:; sth 3,0x28(31); 6:; cmpwi 25,0; bne 7f; addi 3,1,8; li 4,2; bl _s8002C5CC_5; b 8f; 7:; li 3,952; bl _s8002C5CC_6; addi 4,1,8; mr 5,26; mr 6,28; mr 7,27; bl _s8002C5CC_7; mr 4,3; addi 3,31,20; bl _s8002C5CC_8; addi 3,1,8; li 4,2; bl _s8002C5CC_9; 8:; mr 3,31; lwz 0,0x74(1); mtspr 8,0; lmw 25,0x54(1); addi 1,1,112"

extern "C" void _s8002C5CC_0();
extern "C" void _s8002C5CC_1();
extern "C" void _s8002C5CC_2();
extern "C" void _s8002C5CC_3();
extern "C" void _s8002C5CC_4();
extern "C" void _s8002C5CC_5();
extern "C" void _s8002C5CC_6();
extern "C" void _s8002C5CC_7();
extern "C" void _s8002C5CC_8();
extern "C" void _s8002C5CC_9();

struct ERoomWall {
    void ERoomWall_TileWallsSegment();
};

void ERoomWall::ERoomWall_TileWallsSegment() {
}
