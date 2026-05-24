// 0x8003D19C GameData::IsPlayerConnected(unsigned (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 31,4; lwz 3,-26524(13); li 30,0; bl _s8003D19C_0; cmpwi 3,0; beq 1f; cmpwi 31,0; beq 0f; lwz 0,0x34(29); subfic 9,0,0; adde 30,9,0; b 1f; 0:; lwz 0,0x30(29); cmpwi 0,0; bne 1f; li 30,1; 1:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8003D19C_0();

struct GameData {
    void IsPlayerConnected();
};

void GameData::IsPlayerConnected() {
}
