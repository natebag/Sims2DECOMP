// 0x80036E78 (8 bytes)
class ESpriteRender {
public:
    int GetMarked();
};

int ESpriteRender::GetMarked() {
    return *(int*)((char*)this + 0x0);
}
