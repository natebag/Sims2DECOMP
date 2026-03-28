/* 0x80082500 (20 bytes) - MUWrapper::SetDisplayOkType(MUStateMachine::eMUDisplayOk) */
typedef unsigned int u32;

class MUWrapper {
public:
    char pad[0xB4];
    int m_displayOk;
    int m_queryType;
    int m_infoType;
    void SetDisplayOkType(int type);
};

void MUWrapper::SetDisplayOkType(int type) {
    m_displayOk = type;
    *(volatile int*)((char*)this + 0xBC) = 0;
    *(volatile int*)((char*)this + 0xB8) = 0;
}
