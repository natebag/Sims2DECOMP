// 0x803B05FC SimpleReconObject<CasCostumes>::GetType (8b)

class SimpleReconObject_CasCostumes {
public:
    char pad[8];
    int m_type;  // at offset 8
};

int SimpleReconObject_CasCostumes_GetType(SimpleReconObject_CasCostumes* this_) {
    return this_->m_type;
}

extern "C" int _ZNK17SimpleReconObjectI12CasCostumesE7GetTypeEv(SimpleReconObject_CasCostumes* this_) {
    return SimpleReconObject_CasCostumes_GetType(this_);
}
