class ITBTarget {
public:
    char _pad[0x9C];
    float m_userReadTime;

    float GetUserReadTime(void);
};

float ITBTarget::GetUserReadTime(void) {
    return m_userReadTime;
}
