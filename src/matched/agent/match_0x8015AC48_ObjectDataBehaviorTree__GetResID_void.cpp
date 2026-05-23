// 0x8015AC48 ObjectDataBehaviorTree::GetResID(void) (8 B)
struct ObjectDataBehaviorTree { char _pad[0x4]; short m_field; int GetResID(); };
int ObjectDataBehaviorTree::GetResID() { return m_field; }
