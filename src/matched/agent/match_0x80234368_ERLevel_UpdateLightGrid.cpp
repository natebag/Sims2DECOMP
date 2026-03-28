struct TNodeList_EILight {
    char data[0x40];
};

struct EInstance;

struct ELightGrid {
    char data[0x6000];
    void Update(TNodeList_EILight &, EInstance **, int, int);
};

struct ERLevel {
    char pad0[0x18];
    ELightGrid m_lightGrid;
    char pad1[0x2415C];
    TNodeList_EILight m_lights;
    char pad2[0x100];
    int m_numRooms;
    EInstance *m_instances[0x800];
    int m_numInstances;

    void UpdateLightGrid(void);
};

void ERLevel::UpdateLightGrid(void) {
    m_lightGrid.Update(m_lights, m_instances, m_numInstances, m_numRooms);
}
