// 0x80233EA4 ERLevel::UnregisterFloorOTDs(EInstance *) (108 B)

struct EInstance;
struct EOrderTableData;
extern void UnregisterFloorOTDsFromList(EOrderTableData**, EInstance*);
struct ERLevel {
    char pad0[0x2A288];
    EOrderTableData** floorRooms;
    char pad1[0x28];
    int maxRoomIndex;
    void UnregisterFloorOTDs(EInstance* inst);
};

void ERLevel::UnregisterFloorOTDs(EInstance* inst) {
    for (int i = 0; i < maxRoomIndex + 1; i++) {
        UnregisterFloorOTDsFromList(&floorRooms[i], inst);
    }
}
