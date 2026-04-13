// 0x8003D788 GameData::GetLocalizedSimsIntroMovie (32B)

extern int g_language;

struct GameData {
    unsigned int GetLocalizedSimsIntroMovie();
};

unsigned int GameData::GetLocalizedSimsIntroMovie() {
    unsigned int r = 0x2F109B75;
    if (g_language != 1) r = 0xC9761856;
    return r;
}
