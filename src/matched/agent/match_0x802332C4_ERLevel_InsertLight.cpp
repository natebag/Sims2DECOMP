struct TNodeList_EILight {
    int Add(void *);
};

struct EILight {
    char pad[0x78];
    int m_roomIndex;
};

struct ERLevel {
    char pad0[0x18];
    int m_dirty;
    char pad1[0x2A158];
    TNodeList_EILight m_lights;

    void InsertLight(EILight *);
};

void ERLevel::InsertLight(EILight *light) {
    int idx = m_lights.Add(light);
    light->m_roomIndex = idx;
    m_dirty = 1;
}
