// 0x8003B22C (128B) GameData::GamePlayReset(void)
// Batch clear + 2-iteration loop calling Player::Reset, then EMemoryMeterWin::Init.

struct Player {
    char pad[0x10];
    void Reset(int index);
};

struct EMemoryMeterWin {
    void Init();
};

struct GameDataGlobal {
    char pad[0xac];
    int m_fieldAC;
    int m_fieldB0;
    int m_fieldB4;
};

extern GameDataGlobal g_gameDataGlobal __attribute__((section(".data")));

struct GameData {
    char pad0_3[0x4];
    EMemoryMeterWin m_meter;
    char pad5_83[0x84 - 0x5];
    int m_field84;
    char pad88_E3[0xE4 - 0x88];
    int m_flag;
    int m_fieldE8;
    char padEC[0x4];
    int m_fieldF0;
    Player m_players[2];

    void GamePlayReset();
};

void GameData::GamePlayReset() {
    m_flag = 1;
    m_fieldE8 = 0;
    m_fieldF0 = 0;
    m_field84 = 0;
    g_gameDataGlobal.m_fieldB0 = 0;
    g_gameDataGlobal.m_fieldB4 = 0;
    g_gameDataGlobal.m_fieldAC = 0;
    for (int i = 0; i <= 1; i++) {
        m_players[i].Reset(i);
    }
    m_meter.Init();
}
