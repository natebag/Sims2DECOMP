// 0x803B0AB8 SimpleReconObject<CasGenetics>::GetType (8b)

class SimpleReconObject_CasGenetics {
public:
    char pad[8];
    int m_type;  // at offset 8
};

int SimpleReconObject_CasGenetics_GetType(SimpleReconObject_CasGenetics* this_) {
    return this_->m_type;
}

extern "C" int _ZNK17SimpleReconObjectI12CasGeneticsE7GetTypeEv(SimpleReconObject_CasGenetics* this_) {
    return SimpleReconObject_CasGenetics_GetType(this_);
}
