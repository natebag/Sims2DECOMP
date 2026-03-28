class ITBTarget {
public:
    char _pad[0x9C];
    float m_userReadTime;

    float GetUserReadTime();
};

float ITBTarget::GetUserReadTime() {
    return m_userReadTime;
}
