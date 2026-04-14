// 0x800922dc MUStatesSaveNewGame::Reset(void) (24B)

struct MUStatesSaveNewGame {
    char pad[0x1C];
    int m_field1C;
    int m_field20;
    char pad2[0x04];
    int m_field28;
    int m_field2C;
    void Reset(void);
};

void MUStatesSaveNewGame::Reset(void) {
    m_field1C = 0;
    m_field20 = 0;
    m_field28 = 0;
    m_field2C = 0;
}
