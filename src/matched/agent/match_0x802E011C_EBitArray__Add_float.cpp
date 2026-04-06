extern "C" void addBits(void*, int, int);
void EBitArray_Add_float(void* self, float f) {
    addBits(self, *(int*)&f, 32);
}
