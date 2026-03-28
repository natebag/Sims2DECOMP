// 0x800EAB38 (8 bytes) — lwz 3, 220(3); blr
// cXObjectImpl::GetSyncObject(void)

class cXObjectImpl {
public:
    void GetSyncObject(void);
};

__attribute__((naked))
void cXObjectImpl::GetSyncObject(void) {
    asm volatile(
        "lwz 3, 220(3)
"
        "blr
"
    );
}
