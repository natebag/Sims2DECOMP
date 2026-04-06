// FLAGS: -msdata=eabi -G 8
// 0x801617FC (68B)
// CasGenetics::GetGrandparent(bool, unsigned int)

struct CasGenetics {
    void* m_data[2][4];  // Two arrays of 4 pointers
};

struct Grandparent;

Grandparent* CasGenetics_GetGrandparent(CasGenetics* self, int isPaternal, unsigned int index) {
    // Match DOL: li r9,0 first, then beq->skip, li r9,1
    int array_idx = 0;
    if (isPaternal) {
        array_idx = 1;
    }
    
    void** array = (void**)((char*)self + array_idx * 16);
    
    // Get array bounds
    void* start = array[0];
    void* end = array[1];
    unsigned int count = ((unsigned int)((char*)end - (char*)start)) >> 2;
    
    // Bounds check: blt->return element
    if (index >= count) {
        return 0;
    }
    
    // Return element at index
    return ((Grandparent**)start)[index];
}
