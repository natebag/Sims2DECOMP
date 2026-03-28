// 0x802CF95C (8 bytes)
class ERTQuantize {
public:
    int GetPaletteSize();
};

int ERTQuantize::GetPaletteSize() {
    return *(int*)((char*)this + 0x10A8);
}
