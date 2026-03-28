extern int gInstanceContext;

struct EInstance {
    static int GetContext();
};
int EInstance::GetContext() { return gInstanceContext; }
