// 0x803A051C SimpleReconObject<OptionsRecon>::GetType (8b)

class SimpleReconObject_OptionsRecon {
public:
    char pad[8];
    int m_type;  // at offset 8
};

int SimpleReconObject_OptionsRecon_GetType(SimpleReconObject_OptionsRecon* this_) {
    return this_->m_type;
}

extern "C" int _ZNK17SimpleReconObjectI12OptionsReconE7GetTypeEv(SimpleReconObject_OptionsRecon* this_) {
    return SimpleReconObject_OptionsRecon_GetType(this_);
}
