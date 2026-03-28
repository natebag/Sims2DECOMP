// 0x80132984 (12 bytes)
// PropTableImpl::GetID(void)
// lwz r9, 4(r3); lha r3, 4(r9); blr
struct PropData {
    char m_pad[4];
    short m_id;
};

class PropTableImpl {
public:
    int m_pad0;
    PropData* m_data;
    short GetID();
};

short PropTableImpl::GetID() {
    return m_data->m_id;
}
