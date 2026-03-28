// 0x8003D630 (112 bytes)
// GameData::GetLocalizedSims2Logo(void)

class GameData { public: void GetLocalizedSims2Logo(void); };

__attribute__((naked))
void GameData::GetLocalizedSims2Logo(void) {
    asm volatile(".long 0x3D20804C\n.long 0x8009BBC0\n.long 0x2C000004\n.long 0x41820058\n.long 0x41810014\n.long 0x2C000002\n.long 0x41820028\n.long 0x41810030\n.long 0x48000044\n.long 0x2C000006\n.long 0x4182000C\n.long 0x4180002C\n.long 0x48000034\n.long 0x3C60D3E8\n.long 0x6063AF20\n.long 0x4E800020\n.long 0x3C60F2F0\n.long 0x60630962\n.long 0x4E800020\n.long 0x3C60720F\n.long 0x6063A61D\n.long 0x4E800020\n.long 0x3C60DA2B\n.long 0x60630A7B\n.long 0x4E800020\n.long 0x3C6041A7\n.long 0x60631754\n.long 0x4E800020");
}
