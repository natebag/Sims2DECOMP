struct MovieData {
    char pad[0x150];
    void* m_movieHeap;
};

extern MovieData gMovieData;

void* GetDefaultHeap();

void* ESimsApp_GetMovieHeap() {
    void* heap = gMovieData.m_movieHeap;
    if (heap == 0) {
        heap = GetDefaultHeap();
    }
    return heap;
}
