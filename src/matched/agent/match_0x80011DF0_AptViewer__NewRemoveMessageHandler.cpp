/* AptViewer::NewRemoveMessageHandler(UIObjectBase *) at 0x80011DF0 (36B) */

void RemoveMessageHandler(void*);

struct AptViewer {
    void NewRemoveMessageHandler(void* obj);
};

void AptViewer::NewRemoveMessageHandler(void* obj) {
    RemoveMessageHandler(obj);
}
