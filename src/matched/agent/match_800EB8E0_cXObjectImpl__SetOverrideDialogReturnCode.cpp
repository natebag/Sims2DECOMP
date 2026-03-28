// 0x800EB8E0 (8 bytes) — sth 4, -31828(13); blr
// cXObjectImpl::SetOverrideDialogReturnCode(TreeReturnCode)

class cXObjectImpl {
public:
    void SetOverrideDialogReturnCode(TreeReturnCode);
};

__attribute__((naked))
void cXObjectImpl::SetOverrideDialogReturnCode(TreeReturnCode) {
    asm volatile(
        "sth 4, -31828(13)
"
        "blr
"
    );
}
