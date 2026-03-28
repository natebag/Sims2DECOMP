// 0x80058E54 (8 bytes) — li 3, 0; blr
// OptionsRecon::ReadFromMemoryCard(char *, unsigned char)

class OptionsRecon {
public:
    void ReadFromMemoryCard(char *, unsigned char);
};

__attribute__((naked))
void OptionsRecon::ReadFromMemoryCard(char *, unsigned char) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
