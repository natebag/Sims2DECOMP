/* ERModel::CleanMorphTargets(bool) at 0x8031A3C4 (88B) */

extern void CleanMorphTarget(void *, int);

struct ERModelCMT {
    char pad1[0xFC];
    int m_dirty;
    void CleanMorphTargets(int clearFlag);
};

void ERModelCMT::CleanMorphTargets(int clearFlag) {
    for (int i = 0; i <= 11; i++) {
        CleanMorphTarget(this, i);
    }
    if (clearFlag == 0) {
        m_dirty = 1;
    }
}
