// 0x80036E70 (8 bytes)
class ESpriteRender {
public:
    int GetObject();
};

int ESpriteRender::GetObject() {
    return *(int*)((char*)this + 0x8);
}
