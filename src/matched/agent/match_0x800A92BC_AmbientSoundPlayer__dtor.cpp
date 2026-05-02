// 0x800A92BC (116B) AmbientSoundPlayer::~AmbientSoundPlayer(void)
// Variant K: virtual call slot 3 on m_field_8 + clear m0/m4/m8 + delete branch.

void __builtin_delete(void* p);

class SoundCh {
public:
    virtual ~SoundCh();
    virtual void f1();
    virtual void Stop();
};

struct AmbientSoundPlayer {
    int m_field_0;
    int m_field_4;
    SoundCh* m_field_8;
    void dtor(int flag);
};

void AmbientSoundPlayer::dtor(int flag) {
    if (m_field_8 != 0) {
        m_field_8->Stop();
        m_field_8 = 0;
    }
    m_field_4 = 0;
    m_field_0 = 0;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
