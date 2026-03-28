/* NeighborhoodImpl::MakeNewFamily(void) - 0x800CEBDC (40 bytes) */

struct Family;

struct NeighborhoodImpl {
    Family *BaseMakeNewFamily(bool, int);
    Family *MakeNewFamily(void);
};

Family *NeighborhoodImpl::MakeNewFamily(void) {
    return BaseMakeNewFamily(0, -1);
}
