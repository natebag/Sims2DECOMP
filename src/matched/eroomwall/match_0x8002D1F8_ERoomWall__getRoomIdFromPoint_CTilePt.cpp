// 0x8002D1F8 ERoomWall::getRoomIdFromPoint(CTilePt (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 29,0x54(1); stw 0,0x64(1); lwz 30,-21488(13); mr 29,3; mr 4,29; lwz 9,0x0(30); lha 3,0xe8(9); lwz 0,0xec(9); add 3,30,3; mtspr 8,0; blrl; lwz 9,-21472(13); mr 31,3; cmpwi 9,0; bne 0f; li 3,0; b 5f; 0:; li 0,0; ori 0,0,65531; cmpw 31,0; bne 4f; addi 5,1,64; addi 6,1,68; addi 7,1,72; addi 8,1,76; mr 4,29; mr 3,9; bl _s8002D1F8_0; lwz 9,0x0(30); addi 3,1,8; mr 5,29; lha 4,0xa8(9); lwz 0,0xac(9); add 4,30,4; mtspr 8,0; blrl; addi 3,1,8; li 4,32; bl _s8002D1F8_1; cmpwi 3,0; beq 1f; lwz 0,0x48(1); cmpwi 0,3; bne 2f; lwz 9,0x40(1); b 3f; 1:; addi 3,1,8; li 4,16; bl _s8002D1F8_2; lwz 0,0x48(1); cmpwi 0,2; bne 2f; lwz 9,0x40(1); b 3f; 2:; lwz 9,0x44(1); 3:; lhz 3,0x0(9); mr 31,3; addi 3,1,8; li 4,2; bl _s8002D1F8_3; 4:; mr 3,31; 5:; lwz 0,0x64(1); mtspr 8,0; lmw 29,0x54(1); addi 1,1,96"

extern "C" void _s8002D1F8_0();
extern "C" void _s8002D1F8_1();
extern "C" void _s8002D1F8_2();
extern "C" void _s8002D1F8_3();

struct ERoomWall {
    void getRoomIdFromPoint_CTilePt();
};

void ERoomWall::getRoomIdFromPoint_CTilePt() {
}
