// 0x80143464 SpriteSlot::Reset() (56B)
//
// PHASE 1 WALL — Alpha2 park 2026-05-08.
// DOL emits (lis r9; lfs f13,76(r3); lfs f0,-10444(r9); ...); with both-no-sched
// flags, source order produces (lis r9; lfs f0,-10444(r9); lfs f13,76(r3); ...).
// All other 10 insns match perfectly — single adjacent lfs/lfs swap blocks the
// match. Direct swap_adj primary, mirrors AptArray::get pattern from S13 Track I.
//
// Validation evidence: Alpha2 note in docs/tracking/s15-mutator-queue.md (head).
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_swap_adj: a=lfs b=lfs which=first

extern const float lbl_803DD734[3];

struct SpriteSlot {
    char  _0[0x0C];     // 0x00..0x0B padding
    float m_f0c;        // 0x0C — destination of m_f4c copy
    int   m_f10;        // 0x10 — zero
    char  _14[0x04];    // 0x14..0x17 padding
    int   m_f18;        // 0x18 — zero
    int   m_f1c;        // 0x1C — zero
    char  _20[0x28];    // 0x20..0x47 padding
    int   m_f48;        // 0x48 — zero
    float m_f4c;        // 0x4C — source of copy
    float m_f50;        // 0x50 — set to v
    float m_f54;        // 0x54 — set to v
    float m_f58;        // 0x58 — set to v
    float m_f5c;        // 0x5C — set to v

    void Reset();
};

void SpriteSlot::Reset() {
    float v     = lbl_803DD734[0];   // lis r9,-32706; lfs f0,-10444(r9)
    float saved = m_f4c;             // lfs f13,76(r3)
    m_f10 = 0;
    m_f5c = v;
    m_f0c = saved;
    m_f18 = 0;
    m_f1c = 0;
    m_f48 = 0;
    m_f50 = v;
    m_f54 = v;
    m_f58 = v;
}
