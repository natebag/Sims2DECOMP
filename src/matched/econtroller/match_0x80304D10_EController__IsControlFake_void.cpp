// 0x80304D10 EController::IsControlFake(void) (8 B)
struct EController { char _pad[0x1ac]; unsigned m_field; unsigned IsControlFake(); };
unsigned EController::IsControlFake() { return m_field; }
