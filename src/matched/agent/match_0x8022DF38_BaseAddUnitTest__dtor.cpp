// 0x8022DF38 BaseAddUnitTest::~BaseAddUnitTest(void) (4B)
// dtor compiled to blr — avoid dtor syntax (triggers deleting-destructor expansion)
struct BaseAddUnitTest { void _dtor(void); };
void BaseAddUnitTest::_dtor(void) {}
