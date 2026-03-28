class SaveGameTarget {
public:
    char _pad[0x110];
    int m_result;

    int GetResult(void);
};

int SaveGameTarget::GetResult(void) {
    return m_result;
}
