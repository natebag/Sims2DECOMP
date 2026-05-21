// 0x803A0828 (68B) PaneItem::GetSize(void)

class PaneItem {
public:
    void* GetSize();
};

void* PaneItem::GetSize() {
    char* vt = *(char**)((char*)this + 28);
    short adj = *(short*)(vt + 40);
    void* fn = *(void**)(vt + 44);
    char* adj_this = (char*)this + adj;
    ((void (*)(void*))fn)(adj_this);
    return (void*)((char*)this + 20);
}
