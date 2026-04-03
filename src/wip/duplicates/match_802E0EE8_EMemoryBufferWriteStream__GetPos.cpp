// 0x802E0EE8 (8 bytes)
class EMemoryBufferWriteStream {
public:
    int GetPos();
};

int EMemoryBufferWriteStream::GetPos() {
    return *(int*)((char*)this + 0x20);
}
