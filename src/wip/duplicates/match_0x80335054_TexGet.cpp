struct TEXPalette {
    char _p[0x08];
    char *m_data;
};
void *TexGet(TEXPalette *pal, unsigned int idx);
void *TexGet(TEXPalette *pal, unsigned int idx) { return pal->m_data + idx * 8; }
