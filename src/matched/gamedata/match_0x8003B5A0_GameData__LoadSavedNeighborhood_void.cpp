// 0x8003B5A0 GameData::LoadSavedNeighborhood(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; lwz 4,-32056(13); bl _s8003B5A0_0; lis 9,-32697; lwz 0,0x5c6c(9); cmpwi 0,0; beq 0f; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; b 1f; 0:; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; 1:; sth 0,0x86(3); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s8003B5A0_0();

struct GameData {
    void LoadSavedNeighborhood();
};

void GameData::LoadSavedNeighborhood() {
}
