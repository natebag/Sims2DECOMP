// 0x800FE014 _MotiveSort(void*, void*) (84B)
//
// objectsim TU free function. STL-style qsort comparator that orders motive
// pairs by their float value in a per-sim motive table.
//
// Semantics:
//   1. Read int index from each pointer arg (probably std::pair<int, ...> first
//      members, but the comparator only uses the int).
//   2. Look up float value in g_motiveTable[idx].
//   3. Compute delta = float_a - float_b (single precision).
//   4. Tri-state comparator with 0.01 epsilon:
//        delta < -0.01  → -1
//        delta >  0.01  →  1
//        |delta| ≤ 0.01 →  0
//
// FP constants at 0x803DC090 / 0x803DC098 verified as double(-0.01) / double(0.01).
// Motive table pointer lives at SDA[-31824] — accessed via SDA21 reloc on r13.

extern float* g_motiveTable;

int _MotiveSort(void* a, void* b) {
    int ia = *(int*)a;
    int ib = *(int*)b;
    float delta = g_motiveTable[ia] - g_motiveTable[ib];
    if (delta < -0.01) return -1;
    return delta > 0.01;
}
