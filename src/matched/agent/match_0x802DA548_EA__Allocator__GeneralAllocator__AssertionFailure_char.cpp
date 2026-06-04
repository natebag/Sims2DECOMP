// 0x802DA548 EA::Allocator::GeneralAllocator::AssertionFailure(const char*) (60 B)
// If an assertion-failure handler was installed (@ +0x4D0), invoke it with the
// message and the stored user context (@ +0x4D4) through the stored function
// pointer (mtlr/blrl); otherwise do nothing.
namespace EA { namespace Allocator {

typedef void (*AssertFailureFn)(const char* msg, void* context);

struct GeneralAllocator {
    char  pad[0x4D0];
    void* m_assertHandler;   // 0x4D0 = 1232
    void* m_assertContext;   // 0x4D4 = 1236
    void AssertionFailure(const char* msg);
};

void GeneralAllocator::AssertionFailure(const char* msg)
{
    AssertFailureFn fn = (AssertFailureFn)m_assertHandler;
    if (fn != 0)
        fn(msg, m_assertContext);
}

}}
