// 0x8005B360 PlumbBobModel::SetModel (128B)

class EResource {
public:
    virtual void DelRef();
};

class EResourceManager {
public:
    virtual void* AddRef(unsigned int id, void* file, int a);
};

extern EResourceManager g_resourceManager __attribute__((section(".data")));

class PlumbBobModel {
    char pad[0x28];
    EResource* m_model;
public:
    unsigned int SetModel(unsigned int id);
};

unsigned int PlumbBobModel::SetModel(unsigned int id) {
    unsigned int old = 0;
    if (m_model) {
        old = ((unsigned int*)m_model)[2];
    }
    if (id != old) {
        if (m_model) {
            m_model->DelRef();
            m_model = 0;
        }
        if (id != 0) {
            m_model = (EResource*)g_resourceManager.AddRef(id, 0, 0);
        }
    }
    return old;
}
