// 0x8003D6A0 GameData::GetLocalizedEAMovie(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32692; lwz 0,-17472(9); cmpwi 0,6; beq 6f; bgt 0f; cmpwi 0,2; beq 2f; ble 11f; cmpwi 0,4; beq 4f; bgt 5f; b 3f; 0:; cmpwi 0,9; beq 10f; bgt 1f; cmpwi 0,7; beq 8f; cmpwi 0,8; beq 9f; b 11f; 1:; cmpwi 0,10; beq 7f; b 11f; 2:; lis 3,28644; ori 3,3,35920; blr; 3:; lis 3,-16600; ori 3,3,51486; blr; 4:; lis 3,287; ori 3,3,13738; blr; 5:; lis 3,-18849; ori 3,3,2920; blr; 6:; lis 3,-15434; ori 3,3,31601; blr; 7:; lis 3,-6783; ori 3,3,17852; blr; 8:; lis 3,-9876; ori 3,3,44812; blr; 9:; lis 3,10299; ori 3,3,40651; blr; 10:; lis 3,-15301; ori 3,3,27265; blr; 11:; lwz 0,-18460(13); lis 3,-16600; ori 3,3,51486; cmpwi 0,1; beqlr; lis 3,-10834; ori 3,3,51603"

struct GameData {
    void GetLocalizedEAMovie();
};

void GameData::GetLocalizedEAMovie() {
}
