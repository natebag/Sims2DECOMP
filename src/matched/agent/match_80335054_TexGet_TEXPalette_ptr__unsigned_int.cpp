struct TexEntry { int data[2]; };
struct TEXPalette { char pad[8]; TexEntry *m_entries; };
TexEntry *TexGet(TEXPalette *pal, unsigned int idx) { return &pal->m_entries[idx]; }
