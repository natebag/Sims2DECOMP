// 0x800EB8C4 cXObjectImpl::TagGraphicsField (12B)

struct cXObj_TGF {
    char pad[0xE8];
    int m_val;
    void TagGraphicsField();
};

void cXObj_TGF::TagGraphicsField() {
    m_val = 1;
}
