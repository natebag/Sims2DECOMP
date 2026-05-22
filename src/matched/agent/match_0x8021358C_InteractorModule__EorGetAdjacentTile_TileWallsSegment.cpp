// 0x8021358C InteractorModule::EorGetAdjacentTile(TileWallsSegment (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; mr 27,6; mr 26,7; mr 31,4; mr 30,5; mr 3,27; mr 4,26; bl _s8021358C_0; lwz 0,0x0(28); lis 9,-32704; addi 9,9,-11076; rlwinm 3,3,2,0,29; lwzx 29,9,3; cmpwi 0,16; bne 1f; cmpwi 31,0; beq 0f; li 0,2; stw 0,0x0(30); b 5f; 0:; li 0,4; stw 0,0x0(30); b 5f; 1:; cmpwi 0,32; bne 3f; cmpwi 31,0; bne 2f; li 0,3; stw 0,0x0(30); b 5f; 2:; li 0,1; stw 0,0x0(30); b 5f; 3:; cmpwi 0,1; bne 4f; cmpwi 31,0; bne 4f; li 3,1; bl _s8021358C_1; rlwinm 30,29,1,0,30; lis 9,-32696; add 30,30,29; addi 9,9,24096; add 30,30,9; stw 3,0x0(28); mr 4,30; mr 3,27; bl _s8021358C_2; mr 3,26; mr 4,30; bl _s8021358C_3; b 5f; 4:; lwz 0,0x0(28); cmpwi 0,2; bne 5f; cmpwi 31,1; bne 5f; li 3,2; bl _s8021358C_4; rlwinm 30,29,1,0,30; lis 9,-32696; add 30,30,29; addi 9,9,24096; add 30,30,9; stw 3,0x0(28); mr 4,30; mr 3,27; bl _s8021358C_5; mr 3,26; mr 4,30; bl _s8021358C_6; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8021358C_0();
extern "C" void _s8021358C_1();
extern "C" void _s8021358C_2();
extern "C" void _s8021358C_3();
extern "C" void _s8021358C_4();
extern "C" void _s8021358C_5();
extern "C" void _s8021358C_6();
extern "C" void f_8021358C() {}
