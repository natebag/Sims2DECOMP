// 0x800A7CC4 (8 bytes) — li 3, 1; blr
// QuickStringSet::GetDataSourceType(void) const

class QuickStringSet {
public:
    void GetDataSourceType(void) const;
};

__attribute__((naked))
void QuickStringSet::GetDataSourceType(void) const {
    asm volatile(
        "li 3, 1
"
        "blr
"
    );
}
