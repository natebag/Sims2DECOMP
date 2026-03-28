class cXPersonImpl {
public:
    char m_pad[156];
    short m_flags;
    short GetFlags();
};

short cXPersonImpl::GetFlags() {
    return m_flags;
}
