// BitMatrix64::Clear(void)
// Address: 0x8009BD1C | Size: 40 bytes
// Pattern: Wrapper with constant args

typedef unsigned int uint;

void BitMatrix64_Set(void* ptr, int val, int size);

void BitMatrix64__Clear(void* obj) {
    BitMatrix64_Set(obj, 0, 512);
}
