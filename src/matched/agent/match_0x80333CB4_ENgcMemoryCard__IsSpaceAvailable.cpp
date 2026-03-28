struct ENgcMemoryCard {
    int IsSpaceAvailable(unsigned int, int, int *result);
};
int ENgcMemoryCard::IsSpaceAvailable(unsigned int, int, int *result) { *result = 0; return 1; }
