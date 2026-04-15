// 0x800BC97C HouseStats::GetObjectCount (8B)
struct HouseStats {
    char pad[36];
    int m_objectCount;
    int GetObjectCount();
};

int HouseStats::GetObjectCount() { return m_objectCount; }
