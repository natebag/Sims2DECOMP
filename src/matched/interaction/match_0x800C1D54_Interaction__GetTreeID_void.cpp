// 0x800C1D54 Interaction::GetTreeID(void) (8 B)
struct Interaction { char _pad[0x2c]; short m_field; int GetTreeID(); };
int Interaction::GetTreeID() { return m_field; }
