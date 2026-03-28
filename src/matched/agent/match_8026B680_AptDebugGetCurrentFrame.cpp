typedef int AptCharacter;

struct AptCharacterInner {
    char pad_00[0x18];
    int m_currentFrame;
};

struct AptCharacterObj {
    char pad_00[0x4C];
    AptCharacterInner *m_inner;
};

AptCharacterObj *AptGetCharacter(int idx);

int AptDebugGetCurrentFrame(int idx) {
    AptCharacterObj *obj = AptGetCharacter(idx);
    if (obj == 0) {
        return -1;
    }
    AptCharacterInner *inner = obj->m_inner;
    if (inner == 0) {
        return -1;
    }
    return inner->m_currentFrame;
}
