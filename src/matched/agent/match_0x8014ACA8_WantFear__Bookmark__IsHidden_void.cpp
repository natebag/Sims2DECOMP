// FLAGS: -fno-schedule-insns
// 0x8014ACA8 WantFear::Bookmark::IsHidden(void) (16B)
// lwz r9,0x4(r3); lbz r3,0x1d(r9); rlwinm r3,r3,0,31,31; blr
namespace WantFear {
struct BookmarkData { char pad[0x1d]; unsigned char m_flags; };
struct Bookmark { char pad[4]; BookmarkData* m_data; int IsHidden() const; };
int Bookmark::IsHidden() const { return m_data->m_flags & 1; }
}
