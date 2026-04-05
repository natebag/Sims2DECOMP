/* ERModel::SetLatticeWeight(int, int, float) at 0x8031A520 (76B) */

extern int SetWeight(void *, int, float);

struct ERModelSLW {
    char pad1[0xFC];
    int m_dirty;
    char pad2[0x04];
    char *m_lattices;
    void SetLatticeWeight(int latticeIdx, int boneIdx, float weight);
};

void ERModelSLW::SetLatticeWeight(int latticeIdx, int boneIdx, float weight) {
    int result = SetWeight(m_lattices + latticeIdx * 224, boneIdx, weight);
    if (result != 0) {
        m_dirty = 1;
    }
}
