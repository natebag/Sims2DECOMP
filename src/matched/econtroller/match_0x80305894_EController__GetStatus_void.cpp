// 0x80305894 EController::GetStatus(void) (8 B)
struct EController { char _pad[0x4]; unsigned m_field; unsigned GetStatus(); };
unsigned EController::GetStatus() { return m_field; }
