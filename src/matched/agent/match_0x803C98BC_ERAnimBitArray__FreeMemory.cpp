struct EAHeap;
extern EAHeap animHeap;
extern "C" void EAHeap_Free(EAHeap*, void* ptr);

void ERAnimBitArray_FreeMemory(void* self, void* ptr) {
    if (ptr) {
        EAHeap_Free(&animHeap, ptr);
    }
}
