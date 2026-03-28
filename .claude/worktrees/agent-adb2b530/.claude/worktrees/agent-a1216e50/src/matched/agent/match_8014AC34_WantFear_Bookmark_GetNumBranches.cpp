// 0x8014AC34 (12 bytes)
// WantFear::Bookmark::GetNumBranches(void) const
// lwz r9, 4(r3); lha r3, 12(r9); blr
namespace WantFear {

struct BookmarkData {
    char m_pad[12];
    short m_numBranches;
};

class Bookmark {
public:
    int m_pad0;
    BookmarkData* m_data;
    short GetNumBranches() const;
};

short Bookmark::GetNumBranches() const {
    return m_data->m_numBranches;
}

}
