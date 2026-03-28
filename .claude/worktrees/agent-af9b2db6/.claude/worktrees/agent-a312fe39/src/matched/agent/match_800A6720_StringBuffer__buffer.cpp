// 0x800A6720 (8 bytes) — lwz 3, 0(3); blr
// StringBuffer::buffer(void)

class StringBuffer {
public:
    void buffer(void);
};

__attribute__((naked))
void StringBuffer::buffer(void) {
    asm volatile(
        "lwz 3, 0(3)\n"
        "blr\n"
    );
}
