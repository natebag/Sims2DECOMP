// 0x80075B08 (8 bytes) — li 3, 0; blr
// GetSpaceRequiredForPs2HDDSave(void)

__attribute__((naked))
void GetSpaceRequiredForPs2HDDSave(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
