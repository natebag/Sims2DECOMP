// 0x80042194 (8 bytes) — lwz 3, 1144(3); blr
// EGlobal::ListenForController(void)

class EGlobal {
public:
    void ListenForController(void);
};

__attribute__((naked))
void EGlobal::ListenForController(void) {
    asm volatile(
        "lwz 3, 1144(3)\n"
        "blr\n"
    );
}
