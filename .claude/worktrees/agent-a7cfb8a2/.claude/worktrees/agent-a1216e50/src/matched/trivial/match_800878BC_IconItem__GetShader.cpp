// 0x800878BC (8 bytes)
class IconItem {
public:
    int GetShader();
};

int IconItem::GetShader() {
    return *(int*)((char*)this + 0x30);
}
