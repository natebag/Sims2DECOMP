// 0x8000FC68 (8 bytes)
class AptParagraph {
public:
    float GetParagraphHeight();
};

float AptParagraph::GetParagraphHeight() {
    return *(float*)((char*)this + 0x30);
}
