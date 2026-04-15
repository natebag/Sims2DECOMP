/* SetIndividualMemory(int&, int, int) - 0x8013FCDC (40B) */

void SetIndividualMemory(int& bits, int idx, int val);
void SetIndividualMemory(int& bits, int idx, int val) {
    int shift = idx * 3;
    bits = (bits & ~(7 << shift)) | (val << shift);
}
