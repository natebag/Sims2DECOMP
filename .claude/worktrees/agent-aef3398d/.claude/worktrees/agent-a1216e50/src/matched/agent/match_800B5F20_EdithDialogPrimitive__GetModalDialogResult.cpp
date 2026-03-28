// 0x800B5F20 (8 bytes) — lwz 3, 136(3); blr
// EdithDialogPrimitive::GetModalDialogResult(void) const

class EdithDialogPrimitive {
public:
    void GetModalDialogResult(void) const;
};

__attribute__((naked))
void EdithDialogPrimitive::GetModalDialogResult(void) const {
    asm volatile(
        "lwz 3, 136(3)\n"
        "blr\n"
    );
}
