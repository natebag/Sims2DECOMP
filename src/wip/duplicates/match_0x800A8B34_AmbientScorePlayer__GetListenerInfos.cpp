/* AmbientScorePlayer::GetListenerInfos(void) at 0x800A8B34 (8B) */

/* addi r3, r3, 0x20 -- returns pointer to embedded member at offset 0x20 */

struct AmbientScorePlayer {
    char pad[0x20];
    char m_listenerInfos[1];

    void* GetListenerInfos(void);
};

void* AmbientScorePlayer::GetListenerInfos(void) {
    return &m_listenerInfos;
}
