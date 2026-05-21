// 0x8034FF3C ENgcTextureBase::GetPaletteLocation(void) (40B)
// Reads SDA global sTlut (at r13-25896 = 0x804FF3F8), returns old value,
// updates it to ((g+1) & ~0xF) subtracted from (g+1). If g+1 < 0, adds 16 first.

extern int sTlut;

struct ENgcTextureBase {
    int GetPaletteLocation();
};

int ENgcTextureBase::GetPaletteLocation() {
    int g = sTlut;
    int next = g + 1;
    int slot = next;
    if (next < 0)
        slot = g + 16;
    slot &= ~0xF;
    sTlut = next - slot;
    return g;
}
