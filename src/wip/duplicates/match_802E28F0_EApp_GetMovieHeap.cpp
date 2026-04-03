void* GetMovieHeapInternal();

struct EApp_GMH {
    void* GetMovieHeap();
};

void* EApp_GMH::GetMovieHeap() {
    return GetMovieHeapInternal();
}
