// 0x800F9A10 ObjectModuleImpl::IsBuyAndBuildDisabled (36b)
// FLAGS: -fno-schedule-insns

class ObjectModuleImpl {
public:
    char pad[0x2034];
    char* m_buyBuildBegin;
    char* m_buyBuildEnd;

    int IsBuyAndBuildDisabled(void);
};

int ObjectModuleImpl::IsBuyAndBuildDisabled(void) {
    return (((unsigned int)m_buyBuildEnd - (unsigned int)m_buyBuildBegin) >> 2) != 0;
}
