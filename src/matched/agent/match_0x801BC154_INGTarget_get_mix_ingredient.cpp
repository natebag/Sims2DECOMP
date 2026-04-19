// 0x801BC154 (60B) INGTarget::get_mix_ingredient(short) const
// Linear search over 4-slot array of (ptr, _pad) entries starting at
// this + 0x1E0, stride 8. Returns &entry if entry->ing && entry->ing->id
// matches, else 0. No prologue (leaf).

struct Ingredient {
    short id;
};

struct MixSlot {
    Ingredient* ing;
    int _pad;
};

class INGTarget {
public:
    char pad_000[0x1E0];
    MixSlot m_slots[4];
    MixSlot* get_mix_ingredient(short id) const;
};

MixSlot* INGTarget::get_mix_ingredient(short id) const {
    MixSlot* p = (MixSlot*)((char*)this + 0x1E0);
    for (int i = 0; i < 4; ++i) {
        if (p == 0) goto next;
        {
            Ingredient* ing = p->ing;
            if (ing == 0) goto next;
            if (ing->id == id) return p;
        }
next:
        p = (MixSlot*)((char*)p + 8);
    }
    return 0;
}
