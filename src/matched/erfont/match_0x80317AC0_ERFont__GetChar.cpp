// 0x80317AC0 (28B) ERFont::GetChar(void *, bool, int)

class ERFont {
public:
    int GetChar(void* data, bool wide, int idx);
};

int ERFont::GetChar(void* data, bool wide, int idx) {
    if (!wide) return *(unsigned char*)((char*)data + idx);
    return *(unsigned short*)((char*)data + idx * 2);
}
