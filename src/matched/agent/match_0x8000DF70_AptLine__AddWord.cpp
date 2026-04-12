// 0x8000DF70 AptLine::AddWord (56b)

struct AptWord {
    AptWord *next;
    void *parent;
};

struct AptLine {
    void *_pad;
    AptWord *words;
};

void AptLine__AddWord(AptLine *self, AptWord *word) {
    if (!self->words) {
        self->words = word;
    } else {
        AptWord *cur = self->words;
        while (cur->next) cur = cur->next;
        cur->next = word;
    }
    word->parent = self;
}
