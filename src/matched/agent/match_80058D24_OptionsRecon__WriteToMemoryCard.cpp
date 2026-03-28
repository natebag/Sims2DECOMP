// 0x80058D24 (8 bytes) — li 3, 0; blr
// OptionsRecon::WriteToMemoryCard(char *, unsigned char)

class OptionsRecon {
public:
    void WriteToMemoryCard(char *, unsigned char);
};

__attribute__((naked))
void OptionsRecon::WriteToMemoryCard(char *, unsigned char) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
