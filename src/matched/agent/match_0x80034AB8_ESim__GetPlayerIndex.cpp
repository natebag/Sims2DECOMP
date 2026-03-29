// 0x80034AB8 (56 bytes)
/* ESim::GetPlayerIndex(void) */

struct PlayerGlobals {
    char pad[0xBC];
    void *player0;
    void *player1;
};

extern PlayerGlobals g_playerGlobals;

struct ESim_GetPlayerIndex {
    char pad_3D0[0x3D0];
    void *m_playerRef;

    int GetPlayerIndex(void);
};

int ESim_GetPlayerIndex::GetPlayerIndex(void) {
    void *ref = m_playerRef;
    int r = -1;
    void *p0 = g_playerGlobals.player0;
    void *p1 = g_playerGlobals.player1;
    if (ref == p0) return 0;
    if (ref != p1) return r;
    return 1;
}
