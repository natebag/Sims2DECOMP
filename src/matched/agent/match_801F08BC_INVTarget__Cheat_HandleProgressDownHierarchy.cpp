// 0x801F08BC (72 bytes)
// INVTarget::Cheat_HandleProgressDownHierarchy(char *)

class INVTarget { public: void Cheat_HandleProgressDownHierarchy(char *); };

__attribute__((naked))
void INVTarget::Cheat_HandleProgressDownHierarchy(char *) {
    asm volatile(".long 0x89630138\n.long 0x2C0B0001\n.long 0x41820030\n.long 0x4D810020\n.long 0x2C0B0000\n.long 0x4C820020\n.long 0x3D208040\n.long 0xA009879C\n.long 0xB0040000\n.long 0x99630189\n.long 0x89230138\n.long 0x39290001\n.long 0x99230138\n.long 0x4E800020\n.long 0x3D208040\n.long 0xA0098798\n.long 0xB0040000\n.long 0x4BFFFFE4");
}
