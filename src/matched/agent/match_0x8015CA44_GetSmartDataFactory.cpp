// 0x8015CA44 (60B) GetSmartDataFactory(void)
// Lazy singleton initializer; allocates and constructs on first call.

class SmartDataFactory {
public:
    int _data[6];
    SmartDataFactory();
};

extern SmartDataFactory* s_smartDataFactory;

SmartDataFactory* GetSmartDataFactory()
{
    if (s_smartDataFactory == 0) {
        s_smartDataFactory = new SmartDataFactory();
    }
    return s_smartDataFactory;
}
