/* EmitterSpr3dSubmitCB at 0x803AE03C (64 bytes) */

struct EStream;

void* StreamGetPtr(EStream* s);
void StreamWritePtr(void* dest, void* src);

int EmitterSpr3dSubmitCB_b(EStream* s, void* src)
{
    void* dest = (void*)((char*)s + 4);
    void* ptr = StreamGetPtr((EStream*)src);
    StreamWritePtr(dest, ptr);
    return 1;
}
