struct GameData {
    char pad[0x128];
    int m_buildBuyPlayer;
};

int GameData__SetBuildBuyPlayer(GameData* self, int player) {
    int old = self->m_buildBuyPlayer;
    if (player <= 1) {
        if (player >= -1) {
            self->m_buildBuyPlayer = player;
            return old;
        }
    }
    self->m_buildBuyPlayer = -1;
    return old;
}
