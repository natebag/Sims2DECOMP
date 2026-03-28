// 0x800C8860 (8 bytes) — lwz 3, 48(3); blr
// NamespaceSelector::GetTreeSetResource(void)

class NamespaceSelector {
public:
    void GetTreeSetResource(void);
};

__attribute__((naked))
void NamespaceSelector::GetTreeSetResource(void) {
    asm volatile(
        "lwz 3, 48(3)
"
        "blr
"
    );
}
