// EBitArray::SignedBitsToFloatScaler(int) - 0x802E050C (76B)

struct EBitArray {
    float SignedBitsToFloatScaler(int n);
};

float EBitArray::SignedBitsToFloatScaler(int n) {
    return 1.0f / (float)((1 << (n - 1)) - 1);
}
