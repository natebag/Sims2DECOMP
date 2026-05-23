// 0x800CAA40 Neighbor::InitWantsFears(void) (136B)

struct Neighbor {
    void InitWantsFears(void);
};

extern "C" void NB_Pre(void);                     // 0x800cc4e4
extern "C" void NB_SlotInit(Neighbor* self, unsigned int i);  // 0x800cc380
extern "C" void NB_Pre2(Neighbor* self, unsigned int i);       // 0x800cbf84
extern "C" void NB_Post(Neighbor* self);                        // 0x800caac8

void Neighbor::InitWantsFears(void) {
    NB_Pre();
    unsigned int i = 0;
    do {
        NB_SlotInit(this, i);
        i++;
    } while (i <= 4);

    i = 0;
    do {
        NB_SlotInit(this, i + 13);
        i++;
    } while (i <= 3);

    i = 0;
    do {
        NB_Pre2(this, i);
        i++;
    } while (i <= 6);

    NB_Post(this);
}
