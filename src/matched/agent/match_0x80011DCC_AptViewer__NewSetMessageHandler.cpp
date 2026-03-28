/* AptViewer::NewSetMessageHandler(UIObjectBase *) at 0x80011DCC (36B) */

void SetMessageHandler(void*);

struct AptViewer {
    void NewSetMessageHandler(void* obj);
};

void AptViewer::NewSetMessageHandler(void* obj) {
    SetMessageHandler(obj);
}
