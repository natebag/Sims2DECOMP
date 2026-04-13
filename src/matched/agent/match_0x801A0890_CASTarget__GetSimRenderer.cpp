// 0x801A0890 CASTarget::GetSimRenderer (24B)

struct SimRenderer {
    char data[576];
};

struct CASTarget {
    char pad[0xA48];
    SimRenderer m_simRenderers[4];

    SimRenderer* GetSimRenderer(int index);
};

SimRenderer* CASTarget::GetSimRenderer(int index) {
    return &m_simRenderers[index];
}
