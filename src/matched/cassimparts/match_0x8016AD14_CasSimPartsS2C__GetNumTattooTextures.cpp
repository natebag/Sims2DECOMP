// 0x8016AD14 CasSimPartsS2C::GetNumTattooTextures(eTattooTextureTypeS2C) const (72B)
// TRIAGE

class CasSimPartsS2C {
public:
    void* pad0;
    void* m_data;  // offset 4
    int GetNumTattooTextures(int type) const;
    int GetTattoosForLocation(int type, unsigned char* buf) const;
};

int CasSimPartsS2C::GetNumTattooTextures(int type) const {
    int r;
    unsigned char buf[600];
    if (m_data == 0) goto fail;
    if (type > 2) goto fail;
    if (type < 0) goto fail;
    r = GetTattoosForLocation(type, buf);
    goto end;
fail:
    r = 0;
end:
    return r;
}
