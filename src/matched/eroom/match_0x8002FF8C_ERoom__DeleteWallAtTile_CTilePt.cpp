// 0x8002FF8C ERoom::DeleteWallAtTile(CTilePt (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 26,0x50(1); stw 0,0x6c(1); mr 26,3; mr 27,4; mr 31,5; addi 3,1,8; lwz 28,-21488(13); bl _s8002FF8C_0; li 0,0; mr 3,27; stw 0,0x48(1); mr 4,31; bl _s8002FF8C_1; cmpwi 3,3; beq 0f; cmpwi 3,5; beq 0f; cmpwi 3,6; beq 0f; cmpwi 3,15; beq 0f; cmpwi 3,23; bne 1f; 0:; li 0,1; b 2f; 1:; li 0,0; 2:; cmpwi 0,0; bne 3f; cmpwi 3,22; bne 4f; 3:; mr 3,26; mr 4,31; addi 5,1,72; li 6,0; bl _s8002FF8C_2; cmpwi 3,0; bne 8f; 4:; cmpwi 31,16; mfcr 30; beq 5f; cmpwi 31,32; bne 7f; 5:; lwz 9,0x0(28); mr 4,26; lha 3,0x88(9); lwz 0,0x8c(9); add 3,28,3; mtspr 8,0; blrl; cmpwi 3,255; bne 7f; li 4,3; mtcrf 128,30; bne 6f; li 4,4; 6:; lwz 30,0x0(28); mr 3,27; lha 29,0x90(30); addi 30,30,144; add 29,28,29; bl _s8002FF8C_3; lwz 0,0x4(30); mr 5,3; mr 3,29; mr 4,26; mtspr 8,0; blrl; 7:; mr 4,31; mr 3,27; bl _s8002FF8C_4; addi 30,1,16; mr 4,27; mr 3,30; bl _s8002FF8C_5; lwz 9,0x0(28); mr 5,30; mr 4,26; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,28,3; mtspr 8,0; blrl; 8:; lwz 30,0x48(1); addi 3,1,8; li 4,2; bl _s8002FF8C_6; mr 3,30; lwz 0,0x6c(1); mtspr 8,0; lmw 26,0x50(1); addi 1,1,104"

extern "C" void _s8002FF8C_0();
extern "C" void _s8002FF8C_1();
extern "C" void _s8002FF8C_2();
extern "C" void _s8002FF8C_3();
extern "C" void _s8002FF8C_4();
extern "C" void _s8002FF8C_5();
extern "C" void _s8002FF8C_6();

struct ERoom {
    void DeleteWallAtTile_CTilePt();
};

void ERoom::DeleteWallAtTile_CTilePt() {
}
