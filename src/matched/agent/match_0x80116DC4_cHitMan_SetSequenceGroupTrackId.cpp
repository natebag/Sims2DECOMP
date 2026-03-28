/* cHitMan::SetSequenceGroupTrackId(int, ERSoundEvent*) - 0x80116DC4 - 20 bytes */

struct ERSoundEvent;

class cHitMan_SGT2 {
public:
    char _pad[0x54];
    int m_trackIds[64];

    void SetSequenceGroupTrackId(int idx, ERSoundEvent* event);
};

void cHitMan_SGT2::SetSequenceGroupTrackId(int idx, ERSoundEvent* event) {
    m_trackIds[idx + 10] = (int)event;
}
