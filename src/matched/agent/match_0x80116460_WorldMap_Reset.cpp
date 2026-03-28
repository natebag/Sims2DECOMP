/* WorldMap::Reset(void) - 0x80116460 - 68 bytes */

struct SubData { int dummy; };

void WorldMap_CleanupSub(SubData *);
void WorldMap_Init(void *);

struct WorldMap {
    int m_field_00;
    char _pad[0x28];
    SubData m_sub;

    void Reset(void);
};

void WorldMap::Reset(void) {
    if (m_field_00 != 0) {
        WorldMap_CleanupSub(&m_sub);
    }
    WorldMap_Init(this);
}
