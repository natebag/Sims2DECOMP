// 0x8003DDA8 GameData::SetBuildBuyPlayer(int) (44B)

struct GameData {
    char pad[296];
    int m_player;
    int SetBuildBuyPlayer(int p);
};

int GameData::SetBuildBuyPlayer(int p) {
    int old = m_player;
    if (p > 1) goto bad;
    if (p < -1) goto bad;
    m_player = p;
    goto end;
bad:
    m_player = -1;
end:
    return old;
}
