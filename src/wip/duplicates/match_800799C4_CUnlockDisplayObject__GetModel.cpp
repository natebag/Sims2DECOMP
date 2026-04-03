typedef unsigned char u8;
class EIStaticModel;

class CUnlockDisplayObject {
    u8 _pad0[0x14];
    EIStaticModel *m_pModel;
public:
    EIStaticModel *GetModel();
};

EIStaticModel *CUnlockDisplayObject::GetModel() {
    return m_pModel;
}
