// 0x801617FC (68B)
// CasGenetics::GetGrandparent(bool, unsigned int)
// FLAGS: -msdata=eabi -G 8
// ASMPROC_force_reg_at_pos: match="slwi 0,5,2" pos=0 from_reg=0 to_reg=9
// ASMPROC_force_reg_at_pos: match="lwzx 3,11,0" pos=2 from_reg=0 to_reg=9

struct CasGenetics {
    void* m_data[2][4];
};

struct Grandparent;

Grandparent* CasGenetics_GetGrandparent(CasGenetics* self, int isPaternal, unsigned int index) {
    int array_idx = 0;
    if (isPaternal) {
        array_idx = 1;
    }
    int offset = array_idx * 16;
    void* start = ((void**)((char*)offset + (unsigned int)self))[0];
    void* end   = ((void**)((char*)offset + (unsigned int)self))[1];
    int diff = (int)((char*)end - (char*)start);
    unsigned int count = (unsigned int)(diff >> 2);

    if (index < count) {
        return ((Grandparent**)start)[index];
    }
    return 0;
}
