// 0x80088980 (8 bytes) — lwz 3, 72(3); blr
// WrapperPaneBase::GetAlt1Button(void)

class WrapperPaneBase {
public:
    void GetAlt1Button(void);
};

__attribute__((naked))
void WrapperPaneBase::GetAlt1Button(void) {
    asm volatile(
        "lwz 3, 72(3)\n"
        "blr\n"
    );
}
