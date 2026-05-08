// 0x801608A0 (96B)
// CasGenetics::BlendMorphValues(float, float)
// FLAGS: -msdata=eabi -G 8

extern "C" int GetNextRandomNumber(void);

struct CasGenetics {
    float BlendMorphValues(float a, float b);
};

float CasGenetics::BlendMorphValues(float a, float b) {
    unsigned int divisor = 100;
    unsigned int r = (unsigned int)GetNextRandomNumber();
    int mod = (int)(r % divisor);
    return (mod > 49) ? b : a;
}
