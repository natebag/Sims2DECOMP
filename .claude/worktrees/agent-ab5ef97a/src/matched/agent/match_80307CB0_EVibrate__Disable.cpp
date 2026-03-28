/* 0x80307CB0 (12 bytes) - EVibrate::Disable(void) */
class EVibrate { public: int m_enabled; void Disable(); };
void EVibrate::Disable() { m_enabled = 0; }
