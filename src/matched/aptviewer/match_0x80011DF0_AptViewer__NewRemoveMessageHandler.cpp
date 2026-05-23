void RemoveMsgHandlerImpl(void* obj);

void AptViewer_NewRemoveMessageHandler(void* self, void* obj) {
    RemoveMsgHandlerImpl(obj);
}
