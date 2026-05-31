// FLAGS: -fno-schedule-insns
// 0x8000DFA8 AptLine::UnlinkWord(AptWord*) (80 B)
// Removes `word` from the line's singly-linked word list and returns it.
//   AptLine::m_head  @ 0x04   (list head)
//   AptWord::m_next  @ 0x00   (next link)
// Walk the list tracking prev; if `word` is not present return 0, otherwise
// splice it out (through prev->m_next, or through m_head when it is the head)
// and return it. The function returns the unlinked word (cur), which is why
// the compiler keeps cur in r3 and parks `this` in r11 (mr r11,r3).
struct AptWord {
    AptWord* m_next;  // 0x00
};

struct AptLine {
    void* _vtable;    // 0x00
    AptWord* m_head;  // 0x04
    AptWord* UnlinkWord(AptWord* word);
};

AptWord* AptLine::UnlinkWord(AptWord* word) {
    AptWord* prev = 0;
    AptWord* cur = m_head;
    while (cur != 0) {
        if (cur == word)
            break;
        prev = cur;
        cur = cur->m_next;
    }
    if (cur == 0)
        return cur;
    if (prev != 0)
        prev->m_next = cur->m_next;
    else
        m_head = cur->m_next;
    return cur;
}
