/* ENgcScheduler::Flush(void) at 0x8034D9B8 (40B) */

struct ENgcRenderer_SF {
    void Flush();
};

extern char gENgcRenderer[];

struct ENgcScheduler_SF {
    void Flush();
};

void ENgcScheduler_SF::Flush() {
    ((ENgcRenderer_SF*)gENgcRenderer)->Flush();
}
