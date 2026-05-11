// 0x80349FDC ENgcRenderer::ParticleListBegin(unsigned, unsigned) (80B)
//
// PHASE 2 WALL — OpusReviewGuy park 2026-05-11. insert_mr candidate.
// DOL emits a redundant `mr r0, r3` after Malloc to save the return value
// before stores. GCC drops it (76B vs 80B). Insert it back via mutator.
//
// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// ASMPROC_insert_mr: after="bl Malloc" src=3 dst=0
// ASMPROC_force_reg: match="stw 3,18012(30)" from_reg=3 to_reg=0

class EAHeap {
public:
    void* Malloc(unsigned int size, int alignment);
};

extern EAHeap* MainHeap();

class ENgcRenderer {
public:
    char pad[18012];
    void* m_alloc;       // 0x465C (18012)
    unsigned int m_count;  // 0x4660 (18016)
    unsigned int m_flag;   // 0x4664 (18020)

    void ParticleListBegin(unsigned int count, unsigned int flag);
};

void ENgcRenderer::ParticleListBegin(unsigned int count, unsigned int flag)
{
    EAHeap* heap = MainHeap();
    void* p = heap->Malloc(count * 64, 0);
    m_flag  = flag;
    m_count = count;
    m_alloc = p;
}
