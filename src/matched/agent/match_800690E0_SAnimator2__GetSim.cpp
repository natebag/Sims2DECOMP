typedef unsigned char u8;
class ESim;

class SAnimator2 {
    u8 _pad0[8];
    ESim *m_pSim;
public:
    ESim *GetSim();
};

ESim *SAnimator2::GetSim() {
    return m_pSim;
}
