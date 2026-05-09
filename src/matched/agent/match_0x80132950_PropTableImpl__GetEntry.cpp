// FLAGS: -fno-schedule-insns
// 0x80132950 (52B) PropTableImpl::GetEntry(int)
// Length-prefixed array indexed via m_arr->m_data with bounds check.

struct PropEntry;
struct PropArray {
    PropEntry** m_data;
};
class PropTableImpl {
public:
    int _pad;
    PropArray* m_arr;
    PropEntry* GetEntry(int idx);
};

PropEntry* PropTableImpl::GetEntry(int idx)
{
    register PropEntry** data asm("r11") = m_arr->m_data;
    int size = 0;
    if (data) size = ((int*)data)[-1];
    if (idx < size) {
        register int byteoffs asm("r9") = idx * 4;
        return *(PropEntry**)((char*)data + byteoffs);
    }
    return 0;
}
