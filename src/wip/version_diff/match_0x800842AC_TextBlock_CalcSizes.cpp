class TextBlock {
public:
    void CalcSizes(float f, int i);
    void CalcSizes();
};

// External function at 0x80084184
extern "C" void sub_80084184(float, int);

void TextBlock::CalcSizes() {
    // Float constant at 0x803D7150
    float f = *(volatile float*)0x803D7150;
    sub_80084184(f, 0);
}
