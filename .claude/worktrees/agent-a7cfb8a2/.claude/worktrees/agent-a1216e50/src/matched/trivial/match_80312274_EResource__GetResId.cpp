// 0x80312274 (8 bytes)
class EResource {
public:
    int GetResId();
};

int EResource::GetResId() {
    return *(int*)((char*)this + 0x8);
}
