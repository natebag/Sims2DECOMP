// 0x8031A5FC (44B) ERModel::GetNumMorphLattice(int)

struct BSplineVolume_GNL {
    char pad[224];
    int GetNumVolumes(void);
};

struct ERModel_GNL {
    char _pad[260];
    BSplineVolume_GNL *m_260;
    int GetNumMorphLattice(int idx);
};

int ERModel_GNL::GetNumMorphLattice(int idx) {
    return m_260[idx].GetNumVolumes();
}
