/* EGlobal::GetFenceIndex(FenceData *) at 0x80040754 (72B) */

struct FenceData;

struct FenceArray {
    int *m_data;
};

struct EGlobal {
    char pad[0xDC];
    FenceArray *m_fenceArray;
    int GetFenceIndex(FenceData *tile);
};

int EGlobal::GetFenceIndex(FenceData *tile) {
    int *arr = m_fenceArray->m_data;
    int count = 0;
    if (arr != 0) {
        count = *(arr - 1);
    }
    for (int i = 0; i < count; i++) {
        if (arr[i] == (int)tile) {
            return i;
        }
    }
    return 0;
}
