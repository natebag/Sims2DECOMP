class HouseStats {
public:
    char pad[0x24];
    int m_objectCount;

    int GetObjectCount(void);
};

int HouseStats::GetObjectCount(void) {
    return m_objectCount;
}
