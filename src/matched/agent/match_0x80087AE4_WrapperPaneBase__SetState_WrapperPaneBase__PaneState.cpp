// 0x80087AE4 WrapperPaneBase::SetState(WrapperPaneBase::PaneState) (8 B)
typedef unsigned PaneState;
struct WrapperPaneBase { char _pad[0x34]; PaneState m_state; void SetState(PaneState); };
void WrapperPaneBase::SetState(PaneState state) { m_state = state; }
