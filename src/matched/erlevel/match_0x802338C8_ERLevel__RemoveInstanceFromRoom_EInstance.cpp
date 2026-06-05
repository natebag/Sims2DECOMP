// 0x802338C8 ERLevel::RemoveInstanceFromRoom(EInstance *) (156 B)

struct NLIteratorPtrType;
struct ENodeList { void Remove(NLIteratorPtrType* it); };
struct EInstance {
    char pad0[0x54];
    int roomIndex;
    char pad1[4];
    unsigned flags;
    char pad2[0x18];
    NLIteratorPtrType* listNode;
};
struct ERLevel {
    void UnregisterFloorOTDs(EInstance* inst);
    void RemoveInstanceFromRoom(EInstance* inst);
};

void ERLevel::RemoveInstanceFromRoom(EInstance* inst) {
    int room = inst->roomIndex;
    if (room != -1) {
        unsigned flags = inst->flags;
        unsigned special = flags & 0x10000;
        if (special) {
            EInstance*** specialRoomsPtr = (EInstance***)((char*)this + 0x2A284);
            (*specialRoomsPtr)[room] = 0;
        } else {
            if (flags & 0x20000) {
                int base = *(int*)((char*)this + 0x2A280);
                ENodeList* list = (ENodeList*)(room * 12 + base);
                list->Remove(inst->listNode);
                inst->listNode = (NLIteratorPtrType*)special;
            }
            if (flags & 0x8000) {
                UnregisterFloorOTDs(inst);
            }
        }
        inst->roomIndex = -1;
    }
}
