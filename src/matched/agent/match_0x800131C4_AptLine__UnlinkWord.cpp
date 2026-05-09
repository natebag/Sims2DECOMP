// AptLine::UnlinkWord(AptWord*) @ 0x800131C4 (80B)
// DOL passes &result in r6 (4th-arg slot); compiler uses r5. Fix with replace_insn.
// ASMPROC_replace_insn: match="addi 5,1,8" replacement="addi 6,1,8"

struct AptWord;

struct AptLine {
    unsigned int m_flags;
};

void AptLine_FindWord(AptLine*, AptWord*, AptWord**);
void WordPool_Remove(void*, void*);
extern char gWordPool[];

int AptLine_UnlinkWord(AptLine* self, AptWord* word) {
    AptWord* result;
    int found;
    found = 0;
    AptLine_FindWord(self, word, &result);
    if (result != 0) {
        void* data = *(void**)result;
        found = 1;
        WordPool_Remove(gWordPool, data);
        self->m_flags |= 0x10;
    }
    return found;
}
