// 0x80088D20 (8 bytes) — lwz 3, 96(3); blr
// DialogPaneBase::GetTitleTextItem(void)

class DialogPaneBase {
public:
    void GetTitleTextItem(void);
};

__attribute__((naked))
void DialogPaneBase::GetTitleTextItem(void) {
    asm volatile(
        "lwz 3, 96(3)
"
        "blr
"
    );
}
