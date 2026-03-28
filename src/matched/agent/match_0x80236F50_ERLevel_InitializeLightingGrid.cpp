struct ELightGrid {
    void Initialize(void);
};

struct ERLevel {
    char pad0[0x18];
    ELightGrid m_lightGrid;

    void InitializeLightingGrid(void);
};

void ERLevel::InitializeLightingGrid(void) {
    m_lightGrid.Initialize();
}
