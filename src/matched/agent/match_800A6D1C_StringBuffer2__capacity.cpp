// 0x800A6D1C (8 bytes) — lwz 3, 4(3); blr
// StringBuffer2::capacity(void) const

class StringBuffer;

class StringBuffer2 {
public:
    void capacity(void) const;
};

__attribute__((naked))
void StringBuffer2::capacity(void) const {
    asm volatile(
        "lwz 3, 4(3)\n"
        "blr\n"
    );
}
