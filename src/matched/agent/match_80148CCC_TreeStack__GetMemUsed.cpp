// 0x80148CCC (92 bytes)
// TreeStack::GetMemUsed(void)
// NOTE: [VERSION_DIFF] register r9 vs r0 for count
// DOL: srawi. r9,r0,2  (count in r9); mine: srawi. r0,r0,2

class StackElem {
public:
    StackElem* NextFrame() const;
};

class TreeStack {
public:
    char* m_memBase;
    char _pad[4];
    StackElem** m_begin;
    StackElem** m_end;
    int GetMemUsed();
};

static StackElem** _tmp_begin;

int TreeStack::GetMemUsed() {
    _tmp_begin = m_begin;
    int count = (int)(m_end - _tmp_begin);
    if (!count)
        return 0;
    StackElem* last = _tmp_begin[count - 1];
    return (int)((char*)last->NextFrame() - m_memBase);
}
