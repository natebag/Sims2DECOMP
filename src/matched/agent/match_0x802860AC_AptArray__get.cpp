// 0x802860AC AptArray::get(int) const (56B)
//
// First STANDARD-ship byte-match for the `anti_tail_merge` mutator. cc1plus -O2
// emits 12 inst / 48B with a single shared return tail (lwz+blr to the
// gpAptUndefined sentinel) at function end. SN ProDG's DOL output keeps the
// tail block DUPLICATED — once inlined for the index<0 / index>=count exits,
// once at the function tail for the bclr fallthrough — gaining +2 inst / +8B.
//
// Source-level coaxing was tried and confirmed insufficient: the layout choice
// is independent of source structure (volatile reads, statement reorder, and
// sentinel local declarations all leave cc1plus on the merged-tail layout).
//
// Resolution: post-cc1plus .s mutation via the `anti_tail_merge` mutator. It
// inverts the BO=4 anchor branch (idx>=count → bge), retargets it to a fresh
// body label placed AFTER an inlined copy of the tail, and retargets the BO=12
// also_retarget branch (idx<0 → blt) to the new tail label. The original .L7
// block survives at function end to receive the bclr fallthrough.
//
// Validation evidence: cog info `d0653f92` (impl post), `46103d56`
// (OpusReviewGuy verdict).
//
// FLAGS: -msdata=eabi -G 8
// ASMPROC_anti_tail_merge: tail_label=.L7 anchor_branch="bc 4,0,.L7" also_retarget="bc 12,0,.L7"

struct AptValue;
extern AptValue* gpAptUndefined;

struct AptArray {
    char pad[0x24];
    AptValue** m_data;
    int m_capacity;
    int m_count;

    AptValue* get(int index) const;
};

AptValue* AptArray::get(int index) const {
    if (index < 0 || index >= m_count) {
        return gpAptUndefined;
    }
    AptValue* val = m_data[index];
    if (val != 0) {
        return val;
    }
    return gpAptUndefined;
}
