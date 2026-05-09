// FLAGS: -msdata=eabi -G 8
// SAnimator2::handleImpatientIdleAnimation(void) at 0x80064434 (260B)
// SW2 Lane M Pack #1 Blueprint 3.

class AnimRef {
public:
    unsigned int m_id;
};

class EACTrack;

class EAnimController {
public:
    void* SetTrackAnim(int flags, unsigned int id, int unkA, float blend, EACTrack** out);
    void SetTrackPos(EACTrack* track, float pos, bool unk);
};

struct SAnimHost {
    char m_pad[820];
    EAnimController m_ctrl;
};

class EResourceManager {
public:
    char m_pad[16];
    void* GetRef(unsigned int id);
    void DelRef(unsigned int id, int mode);
    void AddRefAsync(unsigned int id);
};

class cXPerson;

extern void GetStdAnimRef(cXPerson* person, int idx, AnimRef** out);
extern EResourceManager g_resourceManager;
extern float g_zeroBlend;
extern char g_zeroPos[16];

class SAnimator2 {
public:
    char m_pad0[4];
    cXPerson* m_person;       // +4
    SAnimHost* m_animSub;     // +8
    char m_pad1[0x61C - 12];
    unsigned int m_stateFlags; // +0x61C
    void handleImpatientIdleAnimation();
};

void SAnimator2::handleImpatientIdleAnimation() {
    if (m_stateFlags & 0x01000000) return;

    AnimRef* ref;
    GetStdAnimRef(m_person, 65, &ref);
    if (!ref) return;

    if (g_resourceManager.GetRef(ref->m_id)) {
        if (m_stateFlags & 0x00040000) {
            g_resourceManager.DelRef(ref->m_id, 1);
        }
        void* tk = m_animSub->m_ctrl.SetTrackAnim(1, ref->m_id, -1, g_zeroBlend, 0);
        m_stateFlags = (m_stateFlags | 0x01000000) & ~0x00040000;
        m_animSub->m_ctrl.SetTrackPos((EACTrack*)tk, *(float*)g_zeroPos, true);
    } else if (!(m_stateFlags & 0x00040000)) {
        g_resourceManager.AddRefAsync(ref->m_id);
        m_stateFlags |= 0x00040000;
    }
}
