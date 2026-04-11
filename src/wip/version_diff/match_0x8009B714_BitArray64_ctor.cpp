// FLAGS: -fno-elide-constructors
// 0x8009B714 BitArray64::BitArray64 (20B)
// DOL:
//   li  r9,0
//   li  r10,0
//   stw r9,0(r3)
//   stw r10,4(r3)
//   blr
// (Scheduled to use 2 registers for parallel issue)

struct BitArray64 {
    unsigned int low;
    unsigned int high;
};

extern "C" void BitArray64_ctor(BitArray64* this_) {
    this_->low = 0;
    this_->high = 0;
}
