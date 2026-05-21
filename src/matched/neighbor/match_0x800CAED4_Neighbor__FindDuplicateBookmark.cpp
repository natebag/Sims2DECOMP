// 0x800CAED4 Neighbor::FindDuplicateBookmark(WantFear::Bookmark &) const (132B)

namespace WantFear {
    struct Bookmark {
        int field00;
        int field04;
        int field08;
        bool IsDuplicateNode(Bookmark& other) const;
    };
}

class Neighbor {
    char pad1[404];
    WantFear::Bookmark* m_bookmarks;
public:
    int FindDuplicateBookmark(WantFear::Bookmark& bookmark) const;
};

int Neighbor::FindDuplicateBookmark(WantFear::Bookmark& bookmark) const {
    unsigned int i = 0;
    unsigned int byte_offset = 0;
    for (; i <= 19; i++, byte_offset += 12) {
        WantFear::Bookmark* bk = (WantFear::Bookmark*)((unsigned int)byte_offset + (unsigned int)m_bookmarks);
        bool active = (bk->field04 != 0);
        if (active && bk->IsDuplicateNode(bookmark)) {
            return i;
        }
    }
    return -1;
}
