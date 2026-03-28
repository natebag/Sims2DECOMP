// 0x800A65E4 (8 bytes) — lwz 3, 4(3); blr
// StringBuffer::capacity(void) const

class StringBuffer {
public:
    void capacity(void) const;
};

__attribute__((naked))
void StringBuffer::capacity(void) const {
    asm volatile(
        "lwz 3, 4(3)\n"
        "blr\n"
    );
}
