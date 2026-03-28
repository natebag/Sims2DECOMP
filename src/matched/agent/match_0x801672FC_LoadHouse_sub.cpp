struct NeighborhoodImpl {
    void UnloadHouseInternal(int);
    NeighborhoodImpl* LoadHouseSub();
};

NeighborhoodImpl* NeighborhoodImpl::LoadHouseSub() {
    UnloadHouseInternal(0);
    return this;
}
