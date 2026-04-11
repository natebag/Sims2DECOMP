// TArray<EVec3, TArrayDefaultAllocator>::operator=(TArray<EVec3, TArrayDefaultAllocator> &)
// Address: 0x8024A9B0 | Size: 48 bytes

typedef void* (*FuncPtr)(void*, void*);
extern FuncPtr gTArrayCopyFunc;

char* TArray_EVec3_op_assign(void* self, void* other) {
    char* result = (char*)gTArrayCopyFunc(self, other);
    return result + 8;
}
