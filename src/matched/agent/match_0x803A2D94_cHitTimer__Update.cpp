// 0x803A2D94 cHitTimer::Update(void) (32 B)

class cHitTimer {
    int m_active;
    int m_counter;
public:
    int Update(void);
};

int cHitTimer::Update(void) {
    if (m_active != 0) {
        m_counter = m_counter + 1;
    }
    return 1;
}
