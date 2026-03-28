/* 0x8036AD98 (12 bytes) - REffectsEmitter::RefreshClear(void) */
class REffectsEmitter { char pad[32]; int m_handle; public: void RefreshClear(); };
void REffectsEmitter::RefreshClear() { m_handle = 0; }
