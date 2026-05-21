// 0x8030EB48 BSplineVolume::GetNumVolumes(void) (40B)

struct BSplineVolume {
    char pad[0x90];
    int m_count;
    int m_valid;
    int GetNumVolumes();
};

int BSplineVolume::GetNumVolumes() {
    if (m_valid == 0) return 0;
    if (m_count > 1) return m_count - 1;
    return 0;
}
