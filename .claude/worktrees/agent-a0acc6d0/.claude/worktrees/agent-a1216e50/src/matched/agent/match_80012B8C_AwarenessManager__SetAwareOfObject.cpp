// 0x80012B8C (68 bytes) — Set awareness target object
// AwarenessManager::SetAwareOfObject(cXObject *)

class cXObject;

class AwarenessManager {
public:
    int SetAwareOfObject(cXObject* obj);
};

__attribute__((naked))
int AwarenessManager::SetAwareOfObject(cXObject* obj) {
    asm volatile(
        "mr 11, 3\n"
        "lwz 0, 28(11)\n"
        "cmpwi 0, 0\n"
        "bne 1f\n"
        "cmpwi 4, 0\n"
        "beq 1f\n"
        "lwz 0, 0(11)\n"
        "li 9, 1\n"
        "stw 4, 28(11)\n"
        "li 3, 1\n"
        "ori 0, 0, 0x20\n"
        "stw 9, 24(11)\n"
        "rlwinm 0, 0, 0, 21, 19\n"
        "stw 0, 0(11)\n"
        "blr\n"
        "1:\n"
        "li 3, 0\n"
        "blr\n"
    );
}
