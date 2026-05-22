// 0x8003D138 GameData::SetTwoPlayerMode(bool) (100B)

class UIDB {
public:
    static int UIDBSetInt(char* name, int val);
};

extern char g_str_TwoPlayerMode[16];
extern char g_TwoPlayerMode_flag[16];

class GameData {
public:
    void SetTwoPlayerMode(bool b);
};

void GameData::SetTwoPlayerMode(bool b) {
    if (b) {
        UIDB::UIDBSetInt(g_str_TwoPlayerMode, 1);
        *(int*)g_TwoPlayerMode_flag = 1;
    } else {
        UIDB::UIDBSetInt(g_str_TwoPlayerMode, 0);
        *(int*)g_TwoPlayerMode_flag = 0;
    }
}
