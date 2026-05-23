// 0x8001CAF8 CameraDirector::GetFrameEffectsManager(void) (8 B)
struct CameraDirector { char _pad[0x2d0]; unsigned m_frameEffectsManager; unsigned GetFrameEffectsManager(); };
unsigned CameraDirector::GetFrameEffectsManager() { return m_frameEffectsManager; }
