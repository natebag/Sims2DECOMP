// 0x80063A14 GameData::GetBuildBuyPlayer(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 1,1,64"

struct GameData {
    void GetBuildBuyPlayer();
};

void GameData::GetBuildBuyPlayer() {
}
