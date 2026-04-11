// EPMDesc::EPMDesc - constructor that sets up resource description
// FLAGS: -O0

extern int EResourceManager_CalcId(char *name);

struct EPMDesc {
    int m_id;       // 0x00
    int m_field4;   // 0x04
    int m_field8;   // 0x08
    int m_fieldC;   // 0x0C
    int m_field10;  // 0x10
    
    EPMDesc(char *name, int flag);
};

EPMDesc::EPMDesc(char *name, int flag) {
    m_id = EResourceManager_CalcId(name);
    m_field10 = 0;
    m_field8 = -1;
    m_fieldC = flag;
    m_field4 = 0;
}
