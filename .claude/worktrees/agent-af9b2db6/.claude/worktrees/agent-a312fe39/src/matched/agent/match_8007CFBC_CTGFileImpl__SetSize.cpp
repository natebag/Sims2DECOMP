// 0x8007CFBC (8 bytes) — li 3, 0; blr
// CTGFileImpl::SetSize(int)

class CTGFileImpl {
public:
    void SetSize(int);
};

__attribute__((naked))
void CTGFileImpl::SetSize(int) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
