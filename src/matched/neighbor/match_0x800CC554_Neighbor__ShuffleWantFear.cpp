// 0x800CC554 Neighbor::ShuffleWantFear(int) (128B)
//
// Parked by SonnetWorker — DOL emits `mr r4, r31; mr r3, r30` (slot first,
// then this) in the else-branch's first call, but GCC scheduler picks the
// reverse order. The loop branch already matches DOL — only the
// non-loop else path needs the swap.
//
// Recipe: 1 swap_adj directive targeting the 4th raw mr/mr adjacent-pair
// hit (0-indexed which=3) in the .s. The first 3 pairs are the prologue
// save + 2 loop-iteration pairs that already match DOL; the 4th (and 5th)
// pairs are the else-branch reversed pairs. With which=3 swap, both
// pair-4 (the reversed first call) and pair-5 (which was already in DOL
// order despite source-listed-after-call-2) align with DOL emission.
//
// ASMPROC_swap_adj: a=mr b=mr which=3

class Neighbor {
    void MakeNewActiveBookmark(unsigned int slot);
    void UpdateUIifNeeded(unsigned int slot, int val);
public:
    void ShuffleWantFear(int n);
};

void Neighbor::ShuffleWantFear(int n) {
    if (n == -1) {
        for (unsigned int i = 0; i <= 6; i++) {
            MakeNewActiveBookmark(i);
            UpdateUIifNeeded(i, 2);
        }
    } else {
        MakeNewActiveBookmark(n);
        UpdateUIifNeeded(n, 2);
    }
}
