// 0x80110840 (92B) ObjSelector::GetMasterSelector(void)

class ObjSelector {
public:
    ObjSelector* GetMasterSelector();
};

ObjSelector* ObjSelector::GetMasterSelector() {
    if (*(ObjSelector**)((char*)this + 96) == 0) {
        char* sub = *(char**)((char*)this + 80);
        char* vt = *(char**)sub;
        short adj = *(short*)(vt + 160);
        void* fn = *(void**)(vt + 164);
        ObjSelector* master = ((ObjSelector* (*)(void*, ObjSelector*))fn)(sub + adj, this);
        *(ObjSelector**)((char*)this + 96) = master;
    }
    return *(ObjSelector**)((char*)this + 96);
}
