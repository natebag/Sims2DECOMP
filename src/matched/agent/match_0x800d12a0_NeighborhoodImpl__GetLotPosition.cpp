// 0x800D12A0 NeighborhoodImpl::GetLotPosition (64B)

struct LotPos { int x; int y; };
extern LotPos g_lotPositionTable[];

struct NeighborhoodImpl {
    void GetLotPosition(int lot, int *x, int *y);
};

void NeighborhoodImpl::GetLotPosition(int lot, int *x, int *y) {
    if ((unsigned)(lot - 1) > 8) {
        *y = 0;
        *x = 0;
        return;
    }
    *x = g_lotPositionTable[lot].x;
    *y = g_lotPositionTable[lot].y;
}
