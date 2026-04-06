// FLAGS: -fno-elide-constructors
// 0x801F0D00 (72 bytes)
// INVTarget::ClearAllCheatStrings(void)

extern "C" void* memset(void* dst, int val, unsigned int size);

void INVTarget_ClearAllCheatStrings(char* self) {
    char* ptr = self + 0x18B;
    int count = 5;
    do {
        memset(ptr, 0, 0x800);
        ptr += 0x800;
    } while (--count != 0);
}
