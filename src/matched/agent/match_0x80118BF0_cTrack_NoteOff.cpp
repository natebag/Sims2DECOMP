// 0x80118BF0 cTrack::NoteOff (52b)

extern int NoteOffTarget(void*);

struct cTrack {
    char pad[0x50];
    void* m_noteOff;
};

int cTrack_NoteOff(cTrack* self) {
    void* p = self->m_noteOff;
    if (!p) return 1;
    return NoteOffTarget(p);
}
