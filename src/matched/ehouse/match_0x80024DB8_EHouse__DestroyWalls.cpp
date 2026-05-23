/* EHouse::DestroyWalls(void) at 0x80024DB8 (76B) */

struct ERoom {
    void Destroy(int);
};

struct ERLevel {
    void ResetLightLocations(void);
};

struct EHouse {
    char pad_00[0x08];
    ERoom* m_room;
    char pad_0c[0x10];
    ERLevel* m_level;

    void DestroyWalls(void);
};

void EHouse::DestroyWalls(void) {
    if (m_room != 0) {
        m_room->Destroy(3);
        m_room = 0;
    }
    m_level->ResetLightLocations();
}
