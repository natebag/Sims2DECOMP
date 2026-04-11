// 0x80321F54 (56b) - TEST
// HDDThread::DoFormat

class HDDThread {
public:
    char _pad[1472];
    int m_field5C0;
    char _skip[4];
    int m_field5C8;
    
    void DoFormatInternal();
    void DoFormat();
};

void HDDThread::DoFormat() {
    this->DoFormatInternal();
    int one = 1;
    this->m_field5C0 = one;
    one = this->m_field5C0;
    this->m_field5C8 = one;
}
