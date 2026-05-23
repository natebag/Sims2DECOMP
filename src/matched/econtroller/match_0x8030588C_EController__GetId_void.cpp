// 0x8030588C EController::GetId(void) (8 B)
struct EController { unsigned m_field; unsigned GetId(); };
unsigned EController::GetId() { return m_field; }
