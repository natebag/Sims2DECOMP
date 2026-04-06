extern "C" void* allocObj(int size);
extern "C" void* initDL(void*, int bufSize);
void* EGraphics_AllocDL(void* self, int mode) {
    void* dl = allocObj(104);
    return initDL(dl, 4096);
}
