// 0x800842AC (44B) TextBlock::CalcSizes(void)
// Forward to internal calc with 0, const-float.

class ERC;

class TextBlock {
public:
    void DrawText(ERC* rc, float scale);
    void CalcSizes();
};

extern char s_textBlockScale[];

void TextBlock::CalcSizes() {
    DrawText((ERC*)0, *(float*)s_textBlockScale);
}
