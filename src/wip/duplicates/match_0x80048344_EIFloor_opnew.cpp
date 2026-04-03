/* EIFloor::operator new(unsigned int, void *) - 0x80048344 - 8 bytes */
/* mr r3, r4; blr */

class EIFloor {
public:
    static void* operator new(unsigned int size, void* ptr);
};

void* EIFloor::operator new(unsigned int, void* ptr) {
    return ptr;
}
