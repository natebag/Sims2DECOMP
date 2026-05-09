// 0x8004bfe4 EParticleEffect::SetAlphaFade(float) (124B)
// Mode dispatch (m_field64==0/1) + Emitter::SetState fade-toggle on alpha threshold.
// 0.005 is a non-SDA constant (lis+lfs) — natural for mid-range float literals.
// blt/bge inverse for NaN-loose < — natural fall-through pattern.

class Emitter {
public:
    void SetState(int, int);
};

struct EParticleObj {
    char pad[0x14c];
    float m_field14c;
};

class EParticleEffect {
public:
    char pad[0x58];
    Emitter* m_field58;
    EParticleObj* m_field5c;
    char pad2[4];
    int m_field64;
    void SetAlphaFade(float alpha);
};

void EParticleEffect::SetAlphaFade(float alpha) {
    if (m_field64 == 0) {
        Emitter* e = m_field58;
        if (e == 0) return;
        if (alpha < 0.005f) {
            e->SetState(4, 0);
        } else {
            e->SetState(4, 1);
        }
    } else if (m_field64 == 1) {
        EParticleObj* p = m_field5c;
        if (p == 0) return;
        p->m_field14c = alpha;
    }
}
