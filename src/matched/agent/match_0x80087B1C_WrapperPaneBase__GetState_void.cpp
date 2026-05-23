// 0x80087B1C WrapperPaneBase::GetState(void) (8 B)
typedef unsigned PaneState;
struct WrapperPaneBase { char _pad[0x34]; PaneState m_state; PaneState GetState(); };
PaneState WrapperPaneBase::GetState() { return m_state; }
