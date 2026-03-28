// 0x80125AD0 (12 bytes)
// cXPersonImpl::IsIdle(void)
// lwz r3, 1332(r3); xori r3, r3, 1; blr
class cXPerson;

class cXPersonImpl {
public:
    char m_pad[1332];
    int m_busy;
    int IsIdle();
};

int cXPersonImpl::IsIdle() {
    return m_busy ^ 1;
}
