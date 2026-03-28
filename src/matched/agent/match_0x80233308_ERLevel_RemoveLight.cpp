struct TNodeList_EILight {
    void *Find(void *);
    void Remove(void *);
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

    void RemoveLight(EILight *);
};

void ERLevel::RemoveLight(EILight *light) {
    void *node = m_lights.Find(light);
    if (node != 0) {
        m_lights.Remove(node);
        light->m_roomIndex = 0;
    }
    m_dirty = 1;
}
