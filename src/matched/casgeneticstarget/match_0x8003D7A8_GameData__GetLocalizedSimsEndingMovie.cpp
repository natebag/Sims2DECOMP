// 0x8003D7A8 GameData::GetLocalizedSimsEndingMovie (32B)

extern int g_language;

struct GameData {
    unsigned int GetLocalizedSimsEndingMovie();
};

unsigned int GameData::GetLocalizedSimsEndingMovie() {
    unsigned int r = 0xE593C635;
    if (g_language != 1) r = 0x96C85353;
    return r;
}
