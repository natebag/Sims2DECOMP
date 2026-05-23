// 0x80090060 ELiveMode::SetIntroCameraState(IntroCameraStartState) (8 B)
typedef unsigned IntroCameraStartState;
struct ELiveMode { char _pad[0xc]; unsigned m_introCameraState; void SetIntroCameraState(IntroCameraStartState); };
void ELiveMode::SetIntroCameraState(IntroCameraStartState state) { m_introCameraState = state; }
