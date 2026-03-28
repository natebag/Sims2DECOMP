// 0x8007CFCC (8 bytes) — li 3, 1; blr
// CTGFileImpl::FlushCache(void)

class CTGFileImpl {
public:
    void FlushCache(void);
};

__attribute__((naked))
void CTGFileImpl::FlushCache(void) {
    asm volatile(
        "li 3, 1\n"
        "blr\n"
    );
}
