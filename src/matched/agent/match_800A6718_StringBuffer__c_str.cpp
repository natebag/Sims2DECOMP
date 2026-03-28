// 0x800A6718 (8 bytes) — lwz 3, 0(3); blr
// StringBuffer::c_str(void) const

class StringBuffer {
public:
    void c_str(void) const;
};

__attribute__((naked))
void StringBuffer::c_str(void) const {
    asm volatile(
        "lwz 3, 0(3)
"
        "blr
"
    );
}
