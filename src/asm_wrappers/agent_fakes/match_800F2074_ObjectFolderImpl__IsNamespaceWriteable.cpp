// 0x800F2074 (8 bytes) — li 3, 0; blr
// ObjectFolderImpl::IsNamespaceWriteable(unsigned int)

class ObjectFolderImpl {
public:
    void IsNamespaceWriteable(unsigned int);
};

__attribute__((naked))
void ObjectFolderImpl::IsNamespaceWriteable(unsigned int) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
