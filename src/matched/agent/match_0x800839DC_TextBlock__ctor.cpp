// 0x800839DC TextBlock::TextBlock(...) (56B)

class ERFont;
class EVec2;
class EVec4;

class TextBlock {
public:
    TextBlock(unsigned short* text, EVec2& a, EVec2& b, EVec4* color, ERFont* font, float scale, bool x, bool y, bool z);
    void Set(unsigned short* text, EVec2& a, EVec2& b, EVec4* color, ERFont* font, float scale, bool x, bool y, bool z);
};

TextBlock::TextBlock(unsigned short* text, EVec2& a, EVec2& b, EVec4* color, ERFont* font, float scale, bool x, bool y, bool z) {
    Set(text, a, b, color, font, scale, x, y, z);
}
