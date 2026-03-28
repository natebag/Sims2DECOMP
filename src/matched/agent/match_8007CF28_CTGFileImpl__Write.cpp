// 0x8007CF28 (8 bytes) — li 3, 0; blr
// CTGFileImpl::Write(void *, int)

class CTGFileImpl {
public:
    void Write(void *, int);
};

__attribute__((naked))
void CTGFileImpl::Write(void *, int) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
