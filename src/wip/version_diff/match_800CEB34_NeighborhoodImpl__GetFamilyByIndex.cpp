/* NeighborhoodImpl::GetFamilyByIndex(int) - 0x800CEB34 (16 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x5C];
    int *m_families;

    int GetFamilyByIndex(int index);
};

int NeighborhoodImpl::GetFamilyByIndex(int index) {
    return *(int *)((char *)m_families + (index << 2));
}
