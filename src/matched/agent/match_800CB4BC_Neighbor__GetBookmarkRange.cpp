/* Neighbor::GetBookmarkRange(bool, unsigned int &, unsigned int &) - 0x800CB4BC (44 bytes) */

struct Neighbor {
    static void GetBookmarkRange(bool isMale, unsigned int &start, unsigned int &end);
};

void Neighbor::GetBookmarkRange(bool isMale, unsigned int &start, unsigned int &end) {
    if (isMale) {
        start = 13;
        end = 20;
    } else {
        start = 0;
        end = 13;
    }
}
