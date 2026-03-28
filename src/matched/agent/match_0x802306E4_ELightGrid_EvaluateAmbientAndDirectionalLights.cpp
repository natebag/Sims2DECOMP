struct RoomData {
    char data[0x54];
    void EvaluateAmbientAndDirectionalLights(void);
};

struct ELightGrid {
    char pad0[0x6020];
    int m_numRooms;
    RoomData m_rooms[1];

    void EvaluateAmbientAndDirectionalLights(void);
};

void ELightGrid::EvaluateAmbientAndDirectionalLights(void) {
    int i;
    for (i = 0; i < m_numRooms; i++) {
        m_rooms[i].EvaluateAmbientAndDirectionalLights();
    }
}
