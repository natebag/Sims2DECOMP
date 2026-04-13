// 0x80161B50 CasListener::CasListener (28b)

extern int __vt_11CasListener[];

struct CasListener {
    int m_pMediator;
    int* m_vtable;
    CasListener();
};

CasListener::CasListener() {
    m_vtable = __vt_11CasListener;
    m_pMediator = 0;
}
