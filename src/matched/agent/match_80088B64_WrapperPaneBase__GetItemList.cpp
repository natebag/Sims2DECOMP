// 0x80088B64 (8 bytes) — addi 3, 3, 8; blr
// WrapperPaneBase::GetItemList(void)

class WrapperPaneBase {
public:
    void GetItemList(void);
};

__attribute__((naked))
void WrapperPaneBase::GetItemList(void) {
    asm volatile(
        "addi 3, 3, 8
"
        "blr
"
    );
}
