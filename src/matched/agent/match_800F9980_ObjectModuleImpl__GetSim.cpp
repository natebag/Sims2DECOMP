// 0x800F9980 (8 bytes) — lwz 3, -21496(13); blr
// ObjectModuleImpl::GetSim(void)

class ObjectModuleImpl {
public:
    void GetSim(void);
};

__attribute__((naked))
void ObjectModuleImpl::GetSim(void) {
    asm volatile(
        "lwz 3, -21496(13)
"
        "blr
"
    );
}
