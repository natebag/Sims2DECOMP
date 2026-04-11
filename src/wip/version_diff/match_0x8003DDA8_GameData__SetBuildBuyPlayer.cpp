struct GameData {
    char pad[0x128];
    int m_buildBuyPlayer;
};

int GameData__SetBuildBuyPlayer(GameData* self, int player) {
    int old = self->m_buildBuyPlayer;
    int newval;
    if (player <= 1 && player >= -1) {
        newval = player;
    } else {
        newval = -1;
    }
    self->m_buildBuyPlayer = newval;
    return old;
}
