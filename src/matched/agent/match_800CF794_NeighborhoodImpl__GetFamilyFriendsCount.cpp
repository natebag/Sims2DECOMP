/* NeighborhoodImpl::GetFamilyFriendsCount(Family *) - 60 bytes */

struct Family {
    char m_pad[0x1C];
    int m_friendsCount;
    int m_dirty;
};

struct NeighborhoodImpl {
    int GetFamilyFriendsCount(Family *family);
    void UpdateFamilyFriendsCount(Family *family);
};

int NeighborhoodImpl::GetFamilyFriendsCount(Family *family) {
    if (family->m_dirty != 0)
        UpdateFamilyFriendsCount(family);
    return family->m_friendsCount;
}
