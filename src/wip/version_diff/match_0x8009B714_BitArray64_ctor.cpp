// MATCH: 0x8009B714 BitArray64::BitArray64 (20 bytes)
// Raw: 39 20 00 00 39 40 00 00 91 23 00 00 91 43 00 04 4E 80 00 20
// FLAGS: -fno-elide-constructors -fno-schedule-insns

struct BitArray64 {
    unsigned int low;
    unsigned int high;
};

// Helper to force register pressure
static inline unsigned int getZero1() { return 0; }
static inline unsigned int getZero2() { return 0; }

extern "C" void BitArray64_ctor(BitArray64* this_) {
    unsigned int z1 = getZero1();
    unsigned int z2 = getZero2();
    this_->low = z1;
    this_->high = z2;
}
