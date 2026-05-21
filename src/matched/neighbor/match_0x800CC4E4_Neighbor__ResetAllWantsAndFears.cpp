// 0x800CC4E4 Neighbor::ResetAllWantsAndFears(void) (112B)

namespace WantFear {
    struct Bookmark {
        int field00;
        int field04;
        int field08;
        void Clear();
    };
}

class Neighbor {
    char pad1[404];
    WantFear::Bookmark* m_bookmarks;
    void* m_slots[7];
    int m_activeSlot;
public:
    void ResetAllWantsAndFears();
};

void Neighbor::ResetAllWantsAndFears() {
    for (unsigned int i = 0; i <= 19; i++) {
        m_bookmarks[i].Clear();
    }
    for (unsigned int j = 0; j < 7; j++) {
        m_slots[j] = 0;
    }
    m_activeSlot = 0;
}
