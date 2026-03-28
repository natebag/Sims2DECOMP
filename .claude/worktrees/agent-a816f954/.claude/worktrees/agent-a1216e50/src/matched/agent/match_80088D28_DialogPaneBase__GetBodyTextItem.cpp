// 0x80088D28 (8 bytes) — lwz 3, 100(3); blr
// DialogPaneBase::GetBodyTextItem(void)

class DialogPaneBase {
public:
    void GetBodyTextItem(void);
};

__attribute__((naked))
void DialogPaneBase::GetBodyTextItem(void) {
    asm volatile(
        "lwz 3, 100(3)\n"
        "blr\n"
    );
}
