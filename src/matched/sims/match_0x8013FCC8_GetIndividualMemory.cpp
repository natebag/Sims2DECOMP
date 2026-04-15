/* GetIndividualMemory(int, int) - 0x8013FCC8 (20 bytes) */
int GetIndividualMemory(int bits, int idx);
int GetIndividualMemory(int bits, int idx) {
    return (bits >> (idx * 3)) & 7;
}
