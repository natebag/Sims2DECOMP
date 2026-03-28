// 0x80090E18 (8 bytes)
class LoadingScreenStateMachine {
public:
    char pad[164];
    int m_loadComplete;

    int IsLoadComplete(void);
};

int LoadingScreenStateMachine::IsLoadComplete(void) {
    return m_loadComplete;
}
