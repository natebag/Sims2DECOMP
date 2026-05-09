// 0x800D3880 (56B) GetNghIndex(int)
// Linear scan of 4-entry global table; returns index of match or -1.

extern int g_nghIndexTable[4];

int GetNghIndex(int target)
{
    int* p = g_nghIndexTable;
    for (int i = 0; i < 4; i++) {
        if (target == *p++) return i;
    }
    return -1;
}
