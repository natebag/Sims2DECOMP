struct GA_GBS {
    int GetBlockSize(void* ptr) const;
};

int GA_GBS::GetBlockSize(void* ptr) const {
    return ((int*)ptr)[-1] & ~7;
}
