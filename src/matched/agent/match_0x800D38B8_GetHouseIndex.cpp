// 0x800D38B8 (56B) GetHouseIndex(int)
// Linear scan of 6-entry global table; returns index of match or -1.

extern int g_houseIndexTable[6];

int GetHouseIndex(int target)
{
    int* p = g_houseIndexTable;
    for (int i = 0; i < 6; i++) {
        if (target == *p++) return i;
    }
    return -1;
}
