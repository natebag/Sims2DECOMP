struct BSplineVolume {
    char _pad[0x80];
    int m_id;
    int GetID();
};
int BSplineVolume::GetID() { return m_id; }
