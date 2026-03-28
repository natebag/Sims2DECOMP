// 0x80036E80 (8 bytes)
class ESpriteRender {
public:
    int GetMarkedAsNew();
};

int ESpriteRender::GetMarkedAsNew() {
    return *(int*)((char*)this + 0x4);
}
