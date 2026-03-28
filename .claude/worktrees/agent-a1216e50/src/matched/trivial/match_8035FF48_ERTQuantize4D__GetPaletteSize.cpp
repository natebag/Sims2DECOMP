// 0x8035FF48 (8 bytes)
class ERTQuantize4D {
public:
    int GetPaletteSize();
};

int ERTQuantize4D::GetPaletteSize() {
    return *(int*)((char*)this + 0x1024);
}
