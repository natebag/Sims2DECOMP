struct UIObjectBase;
extern "C" void AptAuxPCEorGL_SetUiObject(UIObjectBase*);

struct AptViewer {
    void NewSetMessageHandler(UIObjectBase*);
};

void AptViewer::NewSetMessageHandler(UIObjectBase* obj)
{
    AptAuxPCEorGL_SetUiObject(obj);
}

