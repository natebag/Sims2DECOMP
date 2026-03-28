/* 0x80082514 (20 bytes) - MUWrapper::SetQueryType(MUStateMachine::eMUQuery) */
class MUWrapper {
public:
    char pad[0xB4];
    int m_displayOk;
    int m_queryType;
    int m_infoType;
    void SetQueryType(int type);
};

void MUWrapper::SetQueryType(int type) {
    m_queryType = type;
    *(volatile int*)((char*)this + 0xBC) = 0;
    *(volatile int*)((char*)this + 0xB4) = 0;
}
