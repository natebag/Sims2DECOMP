// 0x8007CFC4 (8 bytes) — li 3, 0; blr
// CTGFileImpl::Flush(void)

class CTGFileImpl {
public:
    void Flush(void);
};

__attribute__((naked))
void CTGFileImpl::Flush(void) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
