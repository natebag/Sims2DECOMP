// 0x800F207C (8 bytes) — li 3, 0; blr
// ObjectFolderImpl::IsBehaviorWriteable(unsigned int)

class ObjectFolderImpl {
public:
    void IsBehaviorWriteable(unsigned int);
};

__attribute__((naked))
void ObjectFolderImpl::IsBehaviorWriteable(unsigned int) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
