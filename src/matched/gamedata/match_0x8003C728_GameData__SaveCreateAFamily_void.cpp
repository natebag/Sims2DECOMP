// 0x8003C728 GameData::SaveCreateAFamily(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 7,3; li 10,0; lwz 9,0x78(7); li 8,0; lwz 0,0x620(9); b 1f; 0:; addi 10,10,1; cmpwi 10,3; bgt 2f; lwz 9,0x78(7); rlwinm 11,10,2,0,29; addi 9,9,1568; lwzx 0,9,11; 1:; cmpwi 0,0; beq 0b; li 8,1; 2:; cmpwi 8,0; li 3,1; beq 3f; mr 3,7; bl _s8003C728_0; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s8003C728_0();

struct GameData {
    void SaveCreateAFamily();
};

void GameData::SaveCreateAFamily() {
}
