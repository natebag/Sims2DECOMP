/* Neighbor::GetSlotRange(bool, unsigned int &, unsigned int &) - 0x800CB490 (44 bytes) */

struct Neighbor {
    static void GetSlotRange(bool isMale, unsigned int &start, unsigned int &end);
};

void Neighbor::GetSlotRange(bool isMale, unsigned int &start, unsigned int &end) {
    if (isMale) {
        start = 4;
        end = 7;
    } else {
        start = 0;
        end = 4;
    }
}
