// cXObjectImpl::TryPreloadObject(StackElem *, XPrimParam *) (200 bytes)
// Try to preload an object based on parameter flags

class StackElem;
class XPrimParam;

struct cXObjectImpl {
public:
    int TryPreloadObject(StackElem *elem, XPrimParam *param) {
        // Check parameter flag (offset 4)
        unsigned short paramFlag = *(unsigned short *)((char *)param + 4);

        if (paramFlag & 1) {
            // Flag bit 0 set - call some handler
            // Virtual call at offset 64
            return 0;  // Result: 0, 1
        }

        // Check parameter[0]
        int param0 = *(int *)param;
        if (param0 == 0) {
            // No first parameter
            return 0;  // Result: 0, 0
        }

        // Call virtual method at offset 120
        int result = 0;  // GetSomething(param0)
        if (result == 0) {
            return 0;  // Result: 0, 0
        }

        // Call another virtual at offset 352
        // PreloadObject(result, 0)

        return 1;  // Result: 0, 1 or 0, 2
    }
};
