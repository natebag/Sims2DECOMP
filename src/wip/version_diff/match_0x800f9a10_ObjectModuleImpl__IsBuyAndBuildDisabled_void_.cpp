// 0x800F9A10 (36B) ObjectModuleImpl::IsBuyAndBuildDisabled(void)

struct ObjectModuleImpl_IBBD {
    char pad[0x2034];
    unsigned int m_flags;
    unsigned int m_limit;

    int IsBuyAndBuildDisabled(void);
};

int ObjectModuleImpl_IBBD::IsBuyAndBuildDisabled(void) {
    unsigned int flags = m_flags;
    int result = 1;
    unsigned int limit = m_limit;

    if (flags == limit) {
        return 1;
    }

    unsigned int bits = (limit >> 2) & 3;
    result = 0;
    return result;
}
