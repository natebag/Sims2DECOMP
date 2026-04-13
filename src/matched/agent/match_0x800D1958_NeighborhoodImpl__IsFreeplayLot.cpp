// 0x800D1958 NeighborhoodImpl::IsFreeplayLot (20B)
/* NeighborhoodImpl::IsFreeplayLot(int) - 20 bytes */

struct NeighborhoodImpl {
    static int IsFreeplayLot(int lotNum);
};

int NeighborhoodImpl::IsFreeplayLot(int lotNum) {
    return (unsigned int)(lotNum - 13) <= 3;
}
