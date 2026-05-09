// AnimTableImpl::GetEntry(int) @ 0x800AABC4 (64B)
// m_data at offset 4; *(m_data) = inner array ptr; inner[-1] = count; inner[i] = entry ptr; *entry = result.
// DOL uses single null-return tail; bge+beq both branch to it. Use goto to force same layout.
// DOL allocates r9 for index*4 (freed from m_data); compiled uses r0 (freed from count). Swap.
// ASMPROC_replace_insn: match="slwi 0,4,2" replacement="slwi 9,4,2"
// ASMPROC_replace_insn: match="lwzx 3,3,0" replacement="lwzx 3,3,9"

struct AnimTableImpl_GE {
    int _pad;
    void* m_data;
};

void* AnimTableImpl_GetEntry(AnimTableImpl_GE* self, int index) {
    void* data = self->m_data;
    int count = 0;
    void** inner = *(void***)data;
    if (inner) {
        count = ((int*)inner)[-1];
    }
    if (index >= count) goto null_ret;
    {
        void* entry = inner[index];
        if (!entry) goto null_ret;
        return *(void**)entry;
    }
null_ret:
    return 0;
}
