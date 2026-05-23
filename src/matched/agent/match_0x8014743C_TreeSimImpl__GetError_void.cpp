// 0x8014743C TreeSimImpl::GetError(void) (8 B)
struct TreeSimImpl { char _pad[0x34]; short m_error; int GetError(); };
int TreeSimImpl::GetError() { return m_error; }
