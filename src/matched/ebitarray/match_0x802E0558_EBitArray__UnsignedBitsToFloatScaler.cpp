// EBitArray::UnsignedBitsToFloatScaler(int) - 0x802E0558 (72B)

struct EBitArray {
    float UnsignedBitsToFloatScaler(int n);
};

float EBitArray::UnsignedBitsToFloatScaler(int n) {
    return 1.0f / (float)((1 << n) - 1);
}
