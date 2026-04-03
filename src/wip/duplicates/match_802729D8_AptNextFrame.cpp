struct AptTimeline {
    char pad_00[0x18];
    int m_currentFrame;
    int m_flags;
};

struct AptCharacter {
    char pad_00[0x4C];
    AptTimeline *m_timeline;
};

struct AptActionInterpreter {
    int m_field0;
};

struct LocalContextT {
    int m_field0;
    AptCharacter *m_character;
};

void AptCharacter_gotoFrame(AptCharacter *, int);

void AptActionInterpreter_FunctionAptActionNextFrame(AptActionInterpreter *interp, LocalContextT *ctx) {
    AptCharacter *ch = ctx->m_character;
    int frame = ch->m_timeline->m_currentFrame;
    AptCharacter_gotoFrame(ch, frame + 1);
    ch->m_timeline->m_flags = ch->m_timeline->m_flags & ~0x40;
}
