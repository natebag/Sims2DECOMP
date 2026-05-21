// 0x80052DEC ISimsObjectModel::IsMultiTilePart() (80B)

class ISimsObjectModel {
public:
    int IsMultiTilePart();
};

int ISimsObjectModel::IsMultiTilePart() {
    char* obj = *(char**)((char*)this + 0x328);
    char* vt = *(char**)(obj + 4);
    void* fn = *(void**)(vt + 0x314);
    short adj = *(short*)(vt + 0x310);
    char* ret = ((char*(*)(void*))fn)(obj + adj);
    char* s = *(char**)(ret + 0xC0);
    if (s[9] != 0) return 1;
    return 0;
}
