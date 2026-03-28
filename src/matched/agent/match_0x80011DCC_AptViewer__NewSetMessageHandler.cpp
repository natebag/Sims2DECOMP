void SetMsgHandlerImpl(void* obj);

void AptViewer_NewSetMessageHandler(void* self, void* obj) {
    SetMsgHandlerImpl(obj);
}
