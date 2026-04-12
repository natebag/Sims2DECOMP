// 0x8000E0D4 AptParagraph::AddLine (56b)

struct AptLine {
    AptLine *next;
    char _pad[4];
    void *parent;
};

struct AptParagraph {
    AptLine *lines;
};

void AptParagraph__AddLine(AptParagraph *self, AptLine *line) {
    if (!self->lines) {
        self->lines = line;
    } else {
        AptLine *cur = self->lines;
        while (cur->next) cur = cur->next;
        cur->next = line;
    }
    line->parent = self;
}
