// 0x80112138 ObjTestSim::SetStackObject(cXObject*) (80B) — Tech #47 conditional + assign

class cXObject {};

class ObjTestSim {
public:
    void* m_0;
    cXObject* m_4;
    void SetStackObject(cXObject* obj);
};

void ObjTestSim::SetStackObject(cXObject* obj) {
    if (obj != 0) {
        char* vt = *(char**)((char*)obj + 4);
        short adj = *(short*)(vt + 0x210);
        void* fn = *(void**)(vt + 0x214);
        obj = ((cXObject*(*)(void*))fn)((char*)obj + adj);
    }
    m_4 = obj;
}
