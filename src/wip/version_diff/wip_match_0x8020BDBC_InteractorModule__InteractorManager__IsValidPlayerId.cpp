// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 56B: 4-check validity cascade cr7 bool-folding wall. Parked by SonnetWorker2 + Kmiworker2 S12.
// Original path: src/matched/interactormodule/match_0x8020BDBC_InteractorModule__InteractorManager__IsValidPlayerId.cpp
//
// 0x8020BDBC InteractorModule::InteractorManager::IsValidPlayerId (56B)
// FLAGS: -O0

struct InteractorModule_InteractorManager {
    int m_initialized;
    int m_playerCount;
    int IsValidPlayerId(int id) const;
};

int InteractorModule_InteractorManager::IsValidPlayerId(int id) const {
    if (m_initialized == 0) return 0;
    if (id < 0) return 0;
    if (id >= m_playerCount) return 0;
    if (id > 7) return 0;
    return 1;
}
