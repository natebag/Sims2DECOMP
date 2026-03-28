// 0x800F29F0 (8 bytes) — lwz 3, 1680(3); blr
// ObjectFolderImpl::GetObjectsDatabase(void)

class ObjectFolderImpl {
public:
    void GetObjectsDatabase(void);
};

__attribute__((naked))
void ObjectFolderImpl::GetObjectsDatabase(void) {
    asm volatile(
        "lwz 3, 1680(3)
"
        "blr
"
    );
}
