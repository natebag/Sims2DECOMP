// 0x8012C910 cXPersonImpl::IsInMotiveFailure (12B)

struct cXPerson_IsInMotiveFailure {
    char pad[0x9C];
    unsigned short m_flags;
    int IsInMotiveFailure();
};

int cXPerson_IsInMotiveFailure::IsInMotiveFailure() {
    return (m_flags >> 4) & 1;
}
