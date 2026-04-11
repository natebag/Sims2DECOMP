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
