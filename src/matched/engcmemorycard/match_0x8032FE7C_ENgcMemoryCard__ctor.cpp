// 0x8032FE7C (32B) ENgcMemoryCard::ENgcMemoryCard(void)

extern char ENgcMemoryCard_vt[];  // 0x8046C728
extern void* g_pENgcMemoryCard;   // SDA r13-26384

class ENgcMemoryCard {
public:
    void* m_0;
    int   m_4;
    ENgcMemoryCard();
};

ENgcMemoryCard::ENgcMemoryCard() {
    m_0 = (void*)ENgcMemoryCard_vt;
    m_4 = 0;
    g_pENgcMemoryCard = this;
}
