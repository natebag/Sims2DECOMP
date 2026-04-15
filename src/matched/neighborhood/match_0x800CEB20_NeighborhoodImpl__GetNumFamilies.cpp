/* NeighborhoodImpl::GetNumFamilies(void) - 0x800CEB20 (20 bytes) */
struct FamilyPtr { char data[4]; };
class NeighborhoodImpl {
public:
    char pad[92];
    FamilyPtr* m_begin;
    FamilyPtr* m_end;
    int GetNumFamilies(void);
};
int NeighborhoodImpl::GetNumFamilies(void) {
    return m_end - m_begin;
}
