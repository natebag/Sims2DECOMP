// 0x800BD988 IFFResMap::GetIndexedType(int) (68 B)
// ASMPROC_replace_insn: match="lwz 3,0(3)" replacement="lwz 11,0(3)"
// ASMPROC_replace_insn: match="lwz 0,4(3)" replacement="lwz 0,5(3)"
// ASMPROC_replace_insn: match="lwz 11,0(3)" replacement="lwz 0,4(3)"
// ASMPROC_replace_insn: match="lwz 0,5(3)" replacement="lwz 11,0(3)"
// ASMPROC_replace_insn: match="subf 0,3,0" replacement="subf 0,11,0"
// ASMPROC_replace_insn: match="add 9,9,3" replacement="add 9,11,9"
struct IFFResMap {
    char* m_begin;
    char* m_end;
    int GetIndexedType(int typeIndex);
};

int IFFResMap::GetIndexedType(int typeIndex) {
    char* begin;
    if (typeIndex <= 0) goto null_return;
    begin = m_begin;
    if (typeIndex > ((int)((unsigned int)(m_end - begin) * 0xAAAAAAABu) >> 3)) goto null_return;
    return *(int*)(begin + typeIndex * 24 - 8);
null_return:
    return 0;
}
