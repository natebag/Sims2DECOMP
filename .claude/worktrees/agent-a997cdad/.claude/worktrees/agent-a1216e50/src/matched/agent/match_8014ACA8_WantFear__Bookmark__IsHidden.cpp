/* WantFear::Bookmark::IsHidden - 0x8014ACA8 (16 bytes) */

struct BookmarkData {
    char pad[0x1D];
    unsigned char m_flags;
};

class WantFear {
public:
    class Bookmark {
    public:
        int m_pad;
        BookmarkData *m_data;
        int IsHidden() const;
    };
};

int WantFear::Bookmark::IsHidden() const {
    return m_data->m_flags & 1;
}
