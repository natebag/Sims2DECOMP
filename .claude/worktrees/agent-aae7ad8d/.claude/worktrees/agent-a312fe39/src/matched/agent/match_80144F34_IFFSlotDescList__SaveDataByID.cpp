// 0x80144F34 (112 bytes)
// IFFSlotDescList::SaveDataByID(ObjectDataID &)

class IFFSlotDescList { public: void SaveDataByID(ObjectDataID &); };

__attribute__((naked))
void IFFSlotDescList::SaveDataByID(ObjectDataID &) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x816DABFC\n.long 0x7C7D1B78\n.long 0x7C9E2378\n.long 0x812B0000\n.long 0x809E0000\n.long 0x8009003C\n.long 0xA8690038\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x7C641B78\n.long 0xA8DE0004\n.long 0x3CA0534C\n.long 0x387D0054\n.long 0x60A54F54\n.long 0x38E00000\n.long 0x48268831\n.long 0x20030000\n.long 0x7C601914\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
