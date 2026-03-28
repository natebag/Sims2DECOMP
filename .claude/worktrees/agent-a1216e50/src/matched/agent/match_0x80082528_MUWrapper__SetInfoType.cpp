/* 0x80082528 (20 bytes) - MUWrapper::SetInfoType(MUStateMachine::eMUInfo) */
class MUWrapper {
public:
    char pad[0xB4];
    int m_displayOk;
    int m_queryType;
    int m_infoType;
    void SetInfoType(int type);
};

void MUWrapper::SetInfoType(int type) {
    m_infoType = type;
    *(volatile int*)((char*)this + 0xB8) = 0;
    *(volatile int*)((char*)this + 0xB4) = 0;
}
