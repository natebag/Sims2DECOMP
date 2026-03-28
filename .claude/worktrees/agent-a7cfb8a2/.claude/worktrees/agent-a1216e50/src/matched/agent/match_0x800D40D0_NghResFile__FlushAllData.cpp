/* NghResFile::FlushAllData(void) - 0x800D40D0 (120 bytes) */

struct MemoryCardCache {
    void Destroy(void);
};

struct NghResFile {
    char _pad[0x190];
    MemoryCardCache *m_cache;

    void FlushSection(unsigned int);
    void FlushAllHouseContents(void);
    void FlushCharacterData(bool);
    void FlushNeighborData(void);
    void FlushAllData(void);
};

void NghResFile::FlushAllData(void)
{
    FlushSection(0);
    FlushSection(1);
    FlushSection(2);
    FlushSection(3);
    m_cache->Destroy();
    FlushAllHouseContents();
    FlushCharacterData(1);
    FlushNeighborData();
}
