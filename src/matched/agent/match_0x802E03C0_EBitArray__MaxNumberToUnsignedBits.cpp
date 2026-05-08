// EBitArray::MaxNumberToUnsignedBits(int) - 0x802E03C0 (52B)

struct EBitArray {
    static int MaxNumberToUnsignedBits(int n);
};

int EBitArray::MaxNumberToUnsignedBits(int n) {
    int result = 1;
    if (n <= 1) return result;
    do {
        result++;
        if (result > 31) return result;
    } while (n > (1 << result) - 1);
    return result;
}
