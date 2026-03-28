/* EHouse::Cleanup(void) at 0x80024CFC (188B) */

void EIFloor_DestroyFloors(void);
void ReleaseRef(void*);
void SomeCleanup1(void*);
void SomeCleanup2(void*, int);

struct EHouse {
    char pad_00[0x04];
    void* m_field04;
    void* m_room;
    char pad_0C[0x04];
    int m_field10;
    char pad_14[0x04];
    int m_field18;
    void* m_level;
    int m_field20;
    int m_field24;
    char pad_28[0xFC];
    void* m_field124;

    void Cleanup(void);
    void CleanUpRoomLights(void);
    void DestroyWalls(void);
};

void EHouse::Cleanup(void) {
    if (m_field04 != 0) {
        SomeCleanup2(m_field04, (int)m_level);
    }
    CleanUpRoomLights();
    DestroyWalls();
    EIFloor_DestroyFloors();
    if (m_field04 != 0) {
        SomeCleanup2(m_field04, 3);
    }
    SomeCleanup1(m_level);
    SomeCleanup2(m_level, 0);
    if (m_level != 0) {
        ReleaseRef(m_level);
        m_level = 0;
    }
    m_field20 = 0;
    m_field10 = 1;
    m_field18 = 0;
    if (m_field124 != 0) {
        SomeCleanup2(m_field124, 3);
        m_field124 = 0;
    }
}
