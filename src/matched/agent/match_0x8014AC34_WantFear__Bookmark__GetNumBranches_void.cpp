// FLAGS: -fno-schedule-insns
// 0x8014AC34 WantFear::Bookmark::GetNumBranches(void) (12B)
// lwz r9,0x4(r3); lha r3,0xc(r9); blr
namespace WantFear {
struct BookmarkData { char pad[0xc]; short m_numBranches; };
struct Bookmark { char pad[4]; BookmarkData* m_data; int GetNumBranches() const; };
int Bookmark::GetNumBranches() const { return m_data->m_numBranches; }
}
