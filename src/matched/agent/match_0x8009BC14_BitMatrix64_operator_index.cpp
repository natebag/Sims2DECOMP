/* BitMatrix64::operator[](int) at 0x8009BC14 (12B) */
/* slwi r4, r4, 3; add r3, r3, r4; blr */

struct BitMatrix64 {
    unsigned long long data[1];
    unsigned long long* operator[](int index);
};

unsigned long long* BitMatrix64::operator[](int index) {
    return &data[index];
}
