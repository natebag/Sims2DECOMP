// 0x800D26F8 (8 bytes) — lwz 3, 12(3); blr
// GetNumNghSubSections(NghLayout *)

__attribute__((naked))
void GetNumNghSubSections(NghLayout *) {
    asm volatile(
        "lwz 3, 12(3)
"
        "blr
"
    );
}
