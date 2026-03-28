struct ERTQuantize_GFPS {
    char pad[0x1098];
    int m_fullPaletteSize;
    int GetFullPaletteSize();
};

int ERTQuantize_GFPS::GetFullPaletteSize() {
    return m_fullPaletteSize;
}
