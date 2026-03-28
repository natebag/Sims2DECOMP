// 0x8000FC70 (8 bytes)
class AptParagraph {
public:
    float GetPrintWidth();
};

float AptParagraph::GetPrintWidth() {
    return *(float*)((char*)this + 0x24);
}
