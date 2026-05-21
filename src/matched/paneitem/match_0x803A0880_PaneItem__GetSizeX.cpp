// 0x803A0880 (68B) PaneItem::GetSizeX(void)

class PaneItem {
public:
    float GetSizeX();
};

float PaneItem::GetSizeX() {
    char* vt = *(char**)((char*)this + 28);
    short adj = *(short*)(vt + 40);
    void* fn = *(void**)(vt + 44);
    char* adj_this = (char*)this + adj;
    ((void (*)(void*))fn)(adj_this);
    return *(float*)((char*)this + 20);
}
