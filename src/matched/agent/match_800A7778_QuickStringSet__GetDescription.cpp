// 0x800A7778 (8 bytes) — li 3, 0; blr
// QuickStringSet::GetDescription(int, char)

class StringSet;

class QuickStringSet {
public:
    void GetDescription(int, char);
};

__attribute__((naked))
void QuickStringSet::GetDescription(int, char) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
