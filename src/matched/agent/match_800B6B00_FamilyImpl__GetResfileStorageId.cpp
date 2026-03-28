// 0x800B6B00 (8 bytes) — mr 3, 4; blr
// FamilyImpl::GetResfileStorageId(short)

class FamilyImpl {
public:
    void GetResfileStorageId(short);
};

__attribute__((naked))
void FamilyImpl::GetResfileStorageId(short) {
    asm volatile(
        "mr 3, 4
"
        "blr
"
    );
}
