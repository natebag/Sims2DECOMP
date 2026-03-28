/* cHitMan::RegisterSourceDataRequestHandler - 0x801164A4 - 12 bytes */
/* stw r4, 48(r3); li r3, 1; blr */

typedef int (*SourceDataRequestHandler)(int, int, int*);

class cHitMan {
public:
    char _pad[0x30];
    SourceDataRequestHandler m_handler;

    int RegisterSourceDataRequestHandler(SourceDataRequestHandler handler);
};

int cHitMan::RegisterSourceDataRequestHandler(SourceDataRequestHandler handler) {
    m_handler = handler;
    return 1;
}
