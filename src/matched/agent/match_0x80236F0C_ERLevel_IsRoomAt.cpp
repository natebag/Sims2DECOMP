struct EVec3 { float x, y, z; };

struct ELightGrid {
    char data[0x6000];
    int IsRoomAtLocation(EVec3 &, int);
};

struct ERLevel {
    char pad0[0x18];
    ELightGrid m_lightGrid;
    char pad1[0x2429C];
    int m_numRooms;

    int IsRoomAt(EVec3 &pos, int roomId);
};

int ERLevel::IsRoomAt(EVec3 &pos, int roomId) {
    if (roomId < 0)
        return 0;
    if (roomId >= m_numRooms)
        return 0;
    return m_lightGrid.IsRoomAtLocation(pos, roomId);
}
