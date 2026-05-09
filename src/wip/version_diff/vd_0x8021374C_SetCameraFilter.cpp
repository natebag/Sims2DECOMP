struct InteractorModule {
    int SetCameraFilter(int filter);
};

extern "C" void* GetInputManager();
extern "C" void* GetSessionData(void*, int);
extern "C" void* SomeFunc1(void*);
extern "C" void* SomeFunc2(void*, int);
extern "C" void* SomeFunc3(void*);
extern "C" bool SomeFunc4(void*, void*);

int InteractorModule::SetCameraFilter(int filter) {
    int result = 0;
    void* session = GetSessionData(GetInputManager(), filter);
    if (session) {
        void* obj1 = SomeFunc1(session);
        void* obj2 = SomeFunc2(obj1, filter);
        if (obj2) {
            void* temp = SomeFunc3(session);
            if (SomeFunc4(obj2, temp)) {
                result = 1;
            }
        }
    }
    return result;
}
