// 0x8011784C cTrack::OnEndPlaying(void) (84B)
// TRIAGE

class SomeObj {
public:
    char pad[27];
    unsigned char m_byte27;
    unsigned char m_flag28;
};

class cTrack {
public:
    SomeObj* m_obj;
    bool OnEndPlaying();
    void SetRegister(int, int);
};

bool cTrack::OnEndPlaying() {
    if (m_obj->m_flag28 & 1) {
        SetRegister(17, 0);
    }
    return (m_obj->m_byte27 == 0);
}
