// 0x800DCE44 (76 bytes)
// HierarchySite::HierarchySite(PlacementSpec *)

class HierarchySite { public: void HierarchySite(PlacementSpec *); };

__attribute__((naked))
void HierarchySite::HierarchySite(PlacementSpec *) {
    asm volatile(".long 0x80040000\n.long 0x7C6B1B78\n.long 0x900B0000\n.long 0x81240010\n.long 0x912B0010\n.long 0x2C09FFFF\n.long 0x4182000C\n.long 0x38090001\n.long 0x900B0010\n.long 0x81240004\n.long 0x81440008\n.long 0x7D635B78\n.long 0x912B0004\n.long 0x914B0008\n.long 0x80040014\n.long 0x900B0014\n.long 0x8124000C\n.long 0x912B000C\n.long 0x4E800020");
}
