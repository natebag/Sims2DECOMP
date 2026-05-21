// 0x800B0068 cBoxX::UnpauseAmbient() (76B)

class AmbientScorePlayer {
public:
    void SetPause(bool b);
};

class cBoxX {
public:
    char pad[100];
    AmbientScorePlayer* m_100;
    char pad104[12];
    int m_116;
    void UnpauseAmbient();
};

void cBoxX::UnpauseAmbient() {
    int n = m_116;
    if (n != 0) {
        int newN = n - 1;
        m_116 = newN;
        if (newN != 0) return;
    }
    AmbientScorePlayer* p = m_100;
    if (p == 0) return;
    p->SetPause(false);
}
