// 0x8013554C (60B) iResFile::Unlink(void)
// Singly-linked list unlink: walk g_head chain (next pointer at offset 0); excise this.
// Trick: prev_ptr = &cur->next == cur (since next is offset 0), so cast (iResFile**)cur.

class iResFile {
public:
    iResFile* m_next;
    void Unlink();
};

extern iResFile* g_iResFileHead;  // SDA @ -31680

void iResFile::Unlink()
{
    iResFile** prev = &g_iResFileHead;
    if (*prev == 0) return;
    iResFile* cur;
    do {
        cur = *prev;
        if (cur == this) {
            *prev = cur->m_next;
            return;
        }
        prev = (iResFile**)cur;
    } while (*prev != 0);
}
