// 0x80338428 (92B) ENgcRC::TriStrip(EGEVert *, int)
// State-branched dispatch: count==0 short-circuit, m_state branches base vs singleton.
// Singleton path increments recorder vertCount then forwards.

class EGEVert;

class ENgcRecorder {
public:
    char pad[0x54];
    int  vertCount;     // offset 0x54
};

class ERC {
public:
    ENgcRecorder* m_recorder;   // offset 0
    void TriStrip(EGEVert* verts, int count);
};

class ENgcRenderer {
public:
    void TriStrip(EGEVert* verts, int count);
};

extern char s_renderer[];

class ENgcRC : public ERC {
public:
    char pad[12 - 4];
    int m_state;                // offset 12
    void TriStrip(EGEVert* verts, int count);
};

void ENgcRC::TriStrip(EGEVert* verts, int count) {
    if (count == 0) return;
    if (m_state == 0) {
        m_recorder->vertCount += count;
        ((ENgcRenderer*)s_renderer)->TriStrip(verts, count);
    } else {
        ERC::TriStrip(verts, count);
    }
}
