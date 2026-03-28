// 0x802E0EF8 (8 bytes)
class EMemoryWriteStream {
public:
    int GetPos();
};

int EMemoryWriteStream::GetPos() {
    return *(int*)((char*)this + 0x1C);
}
