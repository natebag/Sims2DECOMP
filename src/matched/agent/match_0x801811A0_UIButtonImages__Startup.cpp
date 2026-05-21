// 0x801811A0 UIButtonImages::Startup() (72B)

extern "C" void* __builtin_new_1(unsigned int size);

class UIButtonImages {
public:
    UIButtonImages();
    void DefineIDs();
    void AddRefAll();
    static void Startup();
};

extern UIButtonImages* g_UIButtonImages_SDA;

extern "C" UIButtonImages* __ct__14UIButtonImagesFv(void* p);

void UIButtonImages::Startup() {
    if (g_UIButtonImages_SDA == 0) {
        UIButtonImages* p = __ct__14UIButtonImagesFv(__builtin_new_1(180));
        g_UIButtonImages_SDA = p;
        p->DefineIDs();
        g_UIButtonImages_SDA->AddRefAll();
    }
}
