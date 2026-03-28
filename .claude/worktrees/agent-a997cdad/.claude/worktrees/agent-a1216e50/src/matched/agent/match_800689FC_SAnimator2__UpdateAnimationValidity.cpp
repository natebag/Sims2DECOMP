// 0x800689FC (68 bytes)
// SAnimator2::UpdateAnimationValidity(void)

class SAnimator2 { public: void UpdateAnimationValidity(void); };

__attribute__((naked))
void SAnimator2::UpdateAnimationValidity(void) {
    asm volatile(".long 0x81230008\n.long 0x39400001\n.long 0x39690334\n.long 0x812B0008\n.long 0x2C090000\n.long 0x41800014\n.long 0x1D2900B0\n.long 0x800B0044\n.long 0x7C004A14\n.long 0x48000008\n.long 0x38000000\n.long 0x2C000000\n.long 0x40820008\n.long 0x39400000\n.long 0x81230008\n.long 0x91490394\n.long 0x4E800020");
}
