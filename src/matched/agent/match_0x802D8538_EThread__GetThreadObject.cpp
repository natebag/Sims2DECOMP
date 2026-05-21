// 0x802D8538 (48B) EThread::GetThreadObject(int)

extern void* g_EThread_head;

namespace EThread {
extern "C" void* GetThreadObject(int id);
}

void* EThread::GetThreadObject(int id) {
    void* node = g_EThread_head;
    void* result = 0;
    goto test;
loop:
    node = *(void**)((char*)node + 820);
test:
    if (node == 0) goto end;
    if (*(int*)((char*)node + 792) == id) {
        result = node;
        goto end;
    }
    goto loop;
end:
    return result;
}
