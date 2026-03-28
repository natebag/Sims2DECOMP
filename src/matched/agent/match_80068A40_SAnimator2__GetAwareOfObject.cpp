typedef unsigned char u8;
class cXObject;

class SAnimator2 {
    u8 _pad0[0x63C];
    cXObject *m_pAwareOfObject;
public:
    cXObject *GetAwareOfObject();
};

cXObject *SAnimator2::GetAwareOfObject() {
    return m_pAwareOfObject;
}
