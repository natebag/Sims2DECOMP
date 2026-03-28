/* HouseStats::GetObjectCount(void) at 0x800BC97C (8B) */

struct HouseStats {
    char pad[0x24];
    int m_objectCount;

    int GetObjectCount(void);
};

int HouseStats::GetObjectCount(void) {
    return m_objectCount;
}
