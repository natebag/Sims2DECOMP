// 0x80160900 (116B)
// CasGenetics::ChoosePersonalityTraits(CasSimDescriptionS2C&)
// FLAGS: -msdata=eabi -G 8

extern "C" int GetNextRandomNumber(void);
extern signed char zodiacPersonalityValues[12][5];

struct CasSimDescriptionS2C {
    char pad[284];
    signed char m_traits[5];
};

struct CasGenetics {
    void ChoosePersonalityTraits(CasSimDescriptionS2C& desc);
};

void CasGenetics::ChoosePersonalityTraits(CasSimDescriptionS2C& desc) {
    unsigned int divisor = 12;
    unsigned int r = (unsigned int)GetNextRandomNumber();
    signed char zodiacIdx = (signed char)(r % divisor);

    for (signed char i = 0; i <= 4; i++) {
        desc.m_traits[i] = zodiacPersonalityValues[zodiacIdx][i];
    }
}
