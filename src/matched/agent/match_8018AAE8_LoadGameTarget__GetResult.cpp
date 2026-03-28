class LoadGameTarget {
public:
    char _pad[0x10C];
    int m_result;

    int GetResult(void);
};

int LoadGameTarget::GetResult(void) {
    return m_result;
}
