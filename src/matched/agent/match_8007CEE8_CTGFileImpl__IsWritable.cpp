// 0x8007CEE8 (8 bytes) — li 3, 0; blr
// CTGFileImpl::IsWritable(void)

class CTGFileImpl {
public:
    void IsWritable(void);
};

__attribute__((naked))
void CTGFileImpl::IsWritable(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
