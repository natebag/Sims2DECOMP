struct GeneralAllocator_CMLH {
    int ChunkMatchesLowHigh(int a, void* chunk, unsigned int b) const;
};
int GeneralAllocator_CMLH::ChunkMatchesLowHigh(int a, void* chunk, unsigned int b) const {
    return 1;
}
