struct ERTQuantize_GPS {
    char pad[0x10A8];
    int m_paletteSize;
    int GetPaletteSize();
};

int ERTQuantize_GPS::GetPaletteSize() {
    return m_paletteSize;
}
