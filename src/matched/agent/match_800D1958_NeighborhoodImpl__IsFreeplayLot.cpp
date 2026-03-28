/* NeighborhoodImpl::IsFreeplayLot(int) - 20 bytes */

struct NeighborhoodImpl {
    static int IsFreeplayLot(int lotNum);
};

int NeighborhoodImpl::IsFreeplayLot(int lotNum) {
    return (unsigned int)(lotNum - 13) <= 3;
}
