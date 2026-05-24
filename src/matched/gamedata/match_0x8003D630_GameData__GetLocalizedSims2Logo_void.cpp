// 0x8003D630 GameData::GetLocalizedSims2Logo(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32692; lwz 0,-17472(9); cmpwi 0,4; beq 5f; bgt 0f; cmpwi 0,2; beq 2f; bgt 3f; b 5f; 0:; cmpwi 0,6; beq 1f; blt 4f; b 5f; 1:; lis 3,-11288; ori 3,3,44832; blr; 2:; lis 3,-3344; ori 3,3,2402; blr; 3:; lis 3,29199; ori 3,3,42525; blr; 4:; lis 3,-9685; ori 3,3,2683; blr; 5:; lis 3,16807; ori 3,3,5972"

struct GameData {
    void GetLocalizedSims2Logo();
};

void GameData::GetLocalizedSims2Logo() {
}
