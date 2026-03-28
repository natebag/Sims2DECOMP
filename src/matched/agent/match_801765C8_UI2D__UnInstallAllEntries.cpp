// 0x801765C8 (96 bytes)
// UI2D::UnInstallAllEntries(char *)

class UI2D { public: void UnInstallAllEntries(char *); };

__attribute__((naked))
void UI2D::UnInstallAllEntries(char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x809E0000\n.long 0x38600000\n.long 0x2C040000\n.long 0x41820028\n.long 0x80040014\n.long 0x83E40004\n.long 0x7C00E800\n.long 0x40820010\n.long 0x7FC3F378\n.long 0x4BFFFC71\n.long 0x38600001\n.long 0x7FE4FB79\n.long 0x4082FFE0\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
