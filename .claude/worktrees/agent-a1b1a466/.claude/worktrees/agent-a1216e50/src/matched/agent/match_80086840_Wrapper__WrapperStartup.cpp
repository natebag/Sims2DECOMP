// 0x80086840 (8 bytes) — stw 4, 136(3); blr
// Wrapper::WrapperStartup(UIObjectBase *)

class UIObjectBase;

class Wrapper {
public:
    void WrapperStartup(UIObjectBase *);
};

__attribute__((naked))
void Wrapper::WrapperStartup(UIObjectBase *) {
    asm volatile(
        "stw 4, 136(3)\n"
        "blr\n"
    );
}
