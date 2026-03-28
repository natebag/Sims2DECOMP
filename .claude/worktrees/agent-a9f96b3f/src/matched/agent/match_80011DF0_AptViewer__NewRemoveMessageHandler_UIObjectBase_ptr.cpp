struct UIObjectBase;
extern "C" void AptAuxPCEorGL_RemoveUiObject(UIObjectBase*);

struct AptViewer {
    void NewRemoveMessageHandler(UIObjectBase*);
};

void AptViewer::NewRemoveMessageHandler(UIObjectBase* obj)
{
    AptAuxPCEorGL_RemoveUiObject(obj);
}

