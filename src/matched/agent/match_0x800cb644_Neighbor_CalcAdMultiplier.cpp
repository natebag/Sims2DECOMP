// 0x800cb644 Neighbor::CalcAdMultiplier(float, float, float) (100B)
// Normalize val into [0..1] along [lo..hi] with swap-detect for inverted bounds.
// NaN-loose `>` / `<` clamps via single-insn ble/bge.
// Leaf — no stwu, all in volatile regs.

class Neighbor {
public:
    static float CalcAdMultiplier(float val, float lo, float hi);
};

float Neighbor::CalcAdMultiplier(float val, float lo, float hi) {
    float t = lo;
    float result = 0.0f;
    int swapped = 0;
    if (lo > hi) {
        lo = hi;
        hi = t;
        swapped = 1;
    }
    if (val > lo) {
        result = 1.0f;
        if (val < hi) {
            result = (val - lo) / (hi - lo);
        }
    }
    if (swapped) result = 1.0f - result;
    return result;
}
