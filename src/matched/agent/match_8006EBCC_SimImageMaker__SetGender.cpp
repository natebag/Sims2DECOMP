typedef unsigned char u8;

class SimImageMaker {
    u8 _pad0[0x88];
    int m_bGender;
public:
    void SetGender(bool);
};

void SimImageMaker::SetGender(bool gender) {
    m_bGender = gender;
}
