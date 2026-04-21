// 0x8033A290 (44B) ENgcRC::ModelMatrixList(EMat4 *, int)
// Different shape: stores count to this+60, then forwards to renderer with the same args.

class EMat4;

class ENgcRenderer {
public:
    void ModelMatrices(EMat4* mats, int count);
};

extern char s_renderer[];

class ENgcRC {
public:
    char pad[60];
    int m_count;  // offset 60
    void ModelMatrixList(EMat4* mats, int count);
};

void ENgcRC::ModelMatrixList(EMat4* mats, int count) {
    m_count = count;
    ((ENgcRenderer*)s_renderer)->ModelMatrices(mats, count);
}
