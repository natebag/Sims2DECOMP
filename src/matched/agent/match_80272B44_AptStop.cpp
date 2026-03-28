struct AptTimeline {
    char pad_00[0x1C];
    int m_flags;
};

struct AptCharacter {
    int m_characterFlags;
    char pad_04[0x48];
    AptTimeline *m_timeline;
};

struct AptActionInterpreter {
    int m_field0;
};

struct LocalContextT {
    int m_field0;
    AptCharacter *m_character;
};

int AptCharacter_getType(AptCharacter *);
int AptCharacter_isStopped(AptCharacter *);

void AptActionInterpreter_FunctionAptActionStop(AptActionInterpreter *interp, LocalContextT *ctx) {
    AptCharacter *ch = ctx->m_character;
    if ((ch->m_characterFlags & 0x08000000) == 0) {
        return;
    }
    int stop = 0;
    if (AptCharacter_getType(ch) == 0x13) {
        stop = AptCharacter_isStopped(ch) == 0;
    }
    if (stop != 0) {
        return;
    }
    AptTimeline *tl = ch->m_timeline;
    if (tl != 0) {
        tl->m_flags = tl->m_flags & ~0x40;
    }
}
