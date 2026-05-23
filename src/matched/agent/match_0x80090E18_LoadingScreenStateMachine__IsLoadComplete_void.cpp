// 0x80090E18 LoadingScreenStateMachine::IsLoadComplete(void) (8 B)
struct LoadingScreenStateMachine { char _pad[0xa4]; unsigned m_isLoadComplete; unsigned IsLoadComplete(); };
unsigned LoadingScreenStateMachine::IsLoadComplete() { return m_isLoadComplete; }
