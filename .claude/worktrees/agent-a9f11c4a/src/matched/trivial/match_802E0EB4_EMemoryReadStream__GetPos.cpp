// 0x802E0EB4 (8 bytes)
class EMemoryReadStream {
public:
    int GetPos();
};

int EMemoryReadStream::GetPos() {
    return *(int*)((char*)this + 0x20);
}
