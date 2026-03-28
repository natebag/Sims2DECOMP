// 0x800F9928 (8 bytes) — lwz 3, -21508(13); blr
// ObjectModuleImpl::GetFolder(void)

class ObjectModuleImpl {
public:
    void GetFolder(void);
};

__attribute__((naked))
void ObjectModuleImpl::GetFolder(void) {
    asm volatile(
        "lwz 3, -21508(13)
"
        "blr
"
    );
}
