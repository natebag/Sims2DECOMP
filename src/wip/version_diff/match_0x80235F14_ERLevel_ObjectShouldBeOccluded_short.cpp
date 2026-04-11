struct RoomInfo {
    char pad[0x128];
    float m_occlusionDist;
};

struct ERLevel {
    char pad0[0x2A284];
    RoomInfo **m_roomPtrs;

    int ObjectShouldBeOccluded(short roomId, float dist);
};

int ERLevel::ObjectShouldBeOccluded(short roomId, float dist) {
    if (roomId == 0)
        return 0;
    RoomInfo *room = m_roomPtrs[roomId];
    if (room == 0)
        return 0;
    return dist < room->m_occlusionDist;
}
