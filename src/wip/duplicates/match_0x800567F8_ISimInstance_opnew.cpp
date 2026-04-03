/* ISimInstance::operator new(unsigned int, void *) - 0x800567F8 - 8 bytes */
/* mr r3, r4; blr */

class ISimInstance {
public:
    static void* operator new(unsigned int size, void* ptr);
};

void* ISimInstance::operator new(unsigned int, void* ptr) {
    return ptr;
}
