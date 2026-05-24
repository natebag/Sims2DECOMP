// FLAGS: -fno-schedule-insns
// 0x80335054 TexGet(TEXPalette) (16B)
// lwz r3,0x8(r3); rlwinm r4,r4,3,0,28; add r3,r3,r4; blr — stride-8 array
struct TEXPalette { char data[8]; };
struct TexCtx {
    char pad[8];
    TEXPalette* m_list;  // offset 8
    TEXPalette* Get(int idx) const;
};
TEXPalette* TexCtx::Get(int idx) const {
    return m_list + idx;
}
