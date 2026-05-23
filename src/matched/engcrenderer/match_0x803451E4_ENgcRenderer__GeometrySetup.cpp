// ENgcRenderer::GeometrySetup(EDLEntry *) at 0x803451E4 (60B)
// DOL:
//   prologue (stmw r30..r31); r30 = this
//   bl UpdateLightingEquation; mr r3,r30; bl UpdateTEVStages
//   m_active = 0; epilogue

struct ENgcRenderer_GS {
    char pad[1296];
    int m_active;
    void GeometrySetup(void* cmd);
    void UpdateLightingEquation();
    void UpdateTEVStages();
};

void ENgcRenderer_GS::GeometrySetup(void* /*cmd*/) {
    UpdateLightingEquation();
    UpdateTEVStages();
    m_active = 0;
}
