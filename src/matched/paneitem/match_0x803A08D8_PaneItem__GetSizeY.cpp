// 0x803A08D8 (68B) PaneItem::GetSizeY(void)

class PaneItem {
public:
    float GetSizeY();
};

float PaneItem::GetSizeY() {
    char* vt = *(char**)((char*)this + 28);
    short adj = *(short*)(vt + 40);
    void* fn = *(void**)(vt + 44);
    char* adj_this = (char*)this + adj;
    ((void (*)(void*))fn)(adj_this);
    return *(float*)((char*)this + 24);
}
