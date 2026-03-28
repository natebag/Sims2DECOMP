/* EmitterSpr3dSubmitCB at 0x803ADFFC (64 bytes) */

struct EStream;

void* StreamGetPtr(EStream* s);
void StreamWritePtr(void* dest, void* src);

int EmitterSpr3dSubmitCB_a(EStream* s, void* dest)
{
    void* ptr = StreamGetPtr((EStream*)((char*)s + 4));
    StreamWritePtr(dest, ptr);
    return 1;
}
