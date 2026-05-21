// 0x800CB2D0 Neighbor::FindActiveSlotIndex(WantFear::Bookmark &) const (92B)

extern short s_invalidSlotIndex;

namespace WantFear {
    struct Bookmark {
        int field00;
        int field04;
    };
}

class Neighbor {
    char pad[408];
    void* m_slots[7];
public:
    int FindActiveSlotIndex(WantFear::Bookmark& bookmark) const;
};

int Neighbor::FindActiveSlotIndex(WantFear::Bookmark& bookmark) const {
    bool active = (bookmark.field04 != 0);
    if (!active) return s_invalidSlotIndex;
    for (unsigned int i = 0; i < 7; i++) {
        if (m_slots[i] == &bookmark) return i;
    }
    return s_invalidSlotIndex;
}
