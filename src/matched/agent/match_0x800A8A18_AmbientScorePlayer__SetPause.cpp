/* AmbientScorePlayer::SetPause(bool) at 0x800A8A18 (248B) */

struct AmbientSoundPlayer {
    int IsValid();
    int Pause();
    int UnPause();
};

struct AmbientScorePlayer {
    int m_state;
    char pad_04[0x08];
    int m_soundPlayers;
    char pad_10[0x0C];
    int m_maxSounds;

    int SetPause(bool pause);
};

int AmbientScorePlayer::SetPause(bool pause)
{
    if (pause) {
        m_state = 2;
    } else {
        m_state = 1;
    }
    if (m_soundPlayers == 0) {
        return 1;
    }
    if (pause) {
        int i = 0;
        if (i < m_maxSounds) {
            int offset = 0;
            do {
                if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->IsValid()) {
                    if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->Pause() != 0) {
                        return 1;
                    }
                }
                i++;
                offset += 0x30;
            } while (i < m_maxSounds);
        }
    } else {
        int i = 0;
        if (i < m_maxSounds) {
            int offset = 0;
            do {
                if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->IsValid()) {
                    if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->UnPause() != 0) {
                        return 1;
                    }
                }
                i++;
                offset += 0x30;
            } while (i < m_maxSounds);
        }
    }
    return 1;
}
