// 0x80090068 ELiveMode::GetIntroCameraState(void) (8 B)
typedef unsigned IntroCameraStartState;
struct ELiveMode { char _pad[0xc]; unsigned m_introCameraState; IntroCameraStartState GetIntroCameraState(); };
IntroCameraStartState ELiveMode::GetIntroCameraState() { return m_introCameraState; }
