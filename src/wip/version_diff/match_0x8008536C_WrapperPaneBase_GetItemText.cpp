class AptString;

// External function at 0x80085034 - GetItem
extern "C" void* sub_80085034(void*, int, int);

class WrapperPaneBase {
public:
    AptString* GetItemText(int type, int index);
};

AptString* WrapperPaneBase::GetItemText(int type, int index) {
    sub_80085034(this, type, index);
    return *(AptString**)((char*)this + 32);
}
