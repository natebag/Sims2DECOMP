struct EInstance {
    char pad[0x54];
    int m_roomIndex;
};

struct ERLevel {
    int GetRoomIndex(EInstance *) const;
    void RemoveInstanceFromRoom(EInstance *);
    void AddInstanceToRoom(EInstance *);
    void NotifyInstanceMoved(EInstance *);
};

void ERLevel::NotifyInstanceMoved(EInstance *inst) {
    int newRoom = GetRoomIndex(inst);
    int curRoom = inst->m_roomIndex;
    if (newRoom != curRoom) {
        if (curRoom != -1) {
            RemoveInstanceFromRoom(inst);
            AddInstanceToRoom(inst);
        }
    }
}
