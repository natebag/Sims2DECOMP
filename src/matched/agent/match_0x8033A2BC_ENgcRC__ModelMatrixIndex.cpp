// 0x8033A2BC (84B) ENgcRC::ModelMatrixIndex(int, int)
// Dispatch split on m_state == 1 (base class) vs default (renderer singleton),
// with max-index tracking for in-range indices on the non-base path.

class ERC {
public:
    void ModelMatrixIndex(int idx, int count);
};

class ENgcRenderer {
public:
    void ModelMatrixIndex(int idx, int count);
};

extern char s_renderer[];

class ENgcRC : public ERC {
public:
    char pad[12 - 4];
    int m_state;    // offset 12
    char pad2[68 - 16];
    int m_maxIdx;   // offset 68
    void ModelMatrixIndex(int idx, int count);
};

void ENgcRC::ModelMatrixIndex(int a, int idx) {
    if (m_state == 1) {
        ERC::ModelMatrixIndex(a, idx);
        return;
    }
    if ((unsigned int)idx <= 247 && idx > m_maxIdx) {
        m_maxIdx = idx;
    }
    ((ENgcRenderer*)s_renderer)->ModelMatrixIndex(a, idx);
}
