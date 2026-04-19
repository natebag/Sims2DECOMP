/* AptCharacterAnimationInst::getSwfVersion(void) at 0x80282FD0 (44B) */

struct SWFObj_GSV {
    char _pad[8];
    unsigned char m_tag; // 8: compare vs 58 (':')
    unsigned char m_ver; // 9: version value
};

struct SWFContainer_GSV {
    char _pad[12];
    SWFObj_GSV* m_obj;  // 12
};

struct AptCharAnimInst_GSV {
    char _pad[0x34];
    SWFContainer_GSV* m_container; // 0x34
    int getSwfVersion() const;
};

int AptCharAnimInst_GSV::getSwfVersion() const {
    register SWFContainer_GSV* cont asm("r9") = m_container;
    register SWFObj_GSV* obj asm("r9") = cont->m_obj;
    if (obj->m_tag != 58) return 6;
    register unsigned char ver asm("r9") = obj->m_ver;
    return (signed char)ver - 48;
}
