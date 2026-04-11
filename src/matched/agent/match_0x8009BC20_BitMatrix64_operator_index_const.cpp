/* BitMatrix64::operator[](int) const at 0x8009BC20 (12B) */
/* slwi r4, r4, 3; add r3, r3, r4; blr */

struct BitMatrix64 {
    unsigned long long data[1];
    const unsigned long long* operator[](int index) const;
};

const unsigned long long* BitMatrix64::operator[](int index) const {
    return &data[index];
}
