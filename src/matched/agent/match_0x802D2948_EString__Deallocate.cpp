extern char gEmptyStr[4];
extern "C" void freeMemory(void*, char*);
void EString_Deallocate(void* self, char* ptr) {
    if (ptr != (char*)gEmptyStr) { freeMemory(self, ptr); }
}
