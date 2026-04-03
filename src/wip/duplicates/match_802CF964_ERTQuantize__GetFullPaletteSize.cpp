// 0x802CF964 (8 bytes)
class ERTQuantize {
public:
    int GetFullPaletteSize();
};

int ERTQuantize::GetFullPaletteSize() {
    return *(int*)((char*)this + 0x1098);
}
