// FLAGS: -msdata=eabi -G 8
// 0x802E01F0 EBitArray::GetFloat (48b)
extern int EBitArray_Get(void*, int, int);

float EBitArray_GetFloat(void* self, int offset) {
    int val = EBitArray_Get(self, offset, 32);
    return *(float*)&val;
}
