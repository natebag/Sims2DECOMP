// 0x8023637C ERLevel::RegisterFloor(EOrderTableData &) (100 B)

struct EInstance;
struct EOrderTableData {
    char pad[0x24];
    EInstance* inst;
    EOrderTableData* next;
};
struct ERLevel {
    char pad0[0x2A288];
    EOrderTableData** floorRooms;
    EOrderTableData* AllocAndCopyOTD(EOrderTableData& data);
    int GetRoomIndex(EInstance* inst) const;
    void RegisterFloor(EOrderTableData& data);
};

void ERLevel::RegisterFloor(EOrderTableData& data) {
    if (floorRooms != 0) {
        EOrderTableData* otd = AllocAndCopyOTD(data);
        int room = GetRoomIndex(otd->inst);
        otd->next = floorRooms[room];
        floorRooms[room] = otd;
    }
}
