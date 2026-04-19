// 0x802B5830 (24B) DOGMA_PoolManager::GetNextOutsideAllocation(void *)

struct DPM_Next {
    char* GetNextOutsideAllocation(char* cur);
};

char* DPM_Next::GetNextOutsideAllocation(char* cur) {
    char* p = *(char**)(cur - 8);
    if (!p) return 0;
    return p + 8;
}
