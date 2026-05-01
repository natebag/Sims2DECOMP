// 0x8033B350 (92B) ENgcRC::LineList(EGEVert *, int)
// Twin of TriStrip(EGEVert*, int): same state-branched dispatch shape.

class EGEVert;

class ENgcRecorder {
public:
    char pad[0x54];
    int  vertCount;     // offset 0x54
};

class ERC {
public:
    ENgcRecorder* m_recorder;
    void LineList(EGEVert* verts, int count);
};

class ENgcRenderer {
public:
    void LineList(EGEVert* verts, int count);
};

extern char s_renderer[];

class ENgcRC : public ERC {
public:
    char pad[12 - 4];
    int m_state;
    void LineList(EGEVert* verts, int count);
};

void ENgcRC::LineList(EGEVert* verts, int count) {
    if (count == 0) return;
    if (m_state == 0) {
        m_recorder->vertCount += count;
        ((ENgcRenderer*)s_renderer)->LineList(verts, count);
    } else {
        ERC::LineList(verts, count);
    }
}
