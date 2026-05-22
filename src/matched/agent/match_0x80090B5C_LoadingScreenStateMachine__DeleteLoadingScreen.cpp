// FLAGS: -fno-schedule-insns
// 0x80090B5C LoadingScreenStateMachine::DeleteLoadingScreen() (92B)
// Tech #47 MI-vcall via raw pointer arithmetic + Tech #18 store-order

class LoadingScreenStateMachine {
public:
    char pad[0x98];
    char* m_98;
    char pad9C[4];
    int m_A0;
    void DeleteLoadingScreen();
};

void LoadingScreenStateMachine::DeleteLoadingScreen() {
    char* s = m_98;
    if (s != 0) {
        char* vt = *(char**)(s + 0x390);
        short adj = *(short*)(vt + 8);
        void (*fn)(void*, int) = *(void (**)(void*, int))(vt + 0xC);
        fn(s + adj, 3);
        m_A0 = 0;
        m_98 = 0;
    }
}
