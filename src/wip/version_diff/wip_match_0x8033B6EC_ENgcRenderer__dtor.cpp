// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 52B: dtor wall. Parked S12.
// Original path: src/matched/engcrenderer/match_0x8033B6EC_ENgcRenderer__dtor.cpp
//
// 0x8033B6EC ENgcRenderer::~ENgcRenderer (52B)

extern int g_ngcRendererActive;

struct ERenderer {
    virtual ~ERenderer();
};

struct ENgcRenderer : ERenderer {
    ~ENgcRenderer();
};

ENgcRenderer::~ENgcRenderer() {
    g_ngcRendererActive = 0;
}
