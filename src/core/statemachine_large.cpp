// statemachine_large.cpp - StateMachine large functions (257-512 bytes)
// Object file: statemachine.obj
// Functions: Update, AddState, DeleteAllStates, deque::_M_reallocate_map
// All NON_MATCHING - vtable dispatch, vector operations, register allocation

#include "types.h"

extern "C" {
    void* operator_new_wrapper(unsigned int size);
    void operator_delete_wrapper(void* ptr);
    void* small_alloc(unsigned int size);
    void small_free(void* ptr);
    void* memcpy(void* dst, const void* src, unsigned int n);
}

// 0x80095b30 - 472 bytes - StateMachine::Update(float)
// NON_MATCHING - complex control flow, vtable dispatch
void StateMachine_Update(void* self, float dt) {
    char* _this = (char*)self;
    if (*(int*)(_this + 0x94) == 0) return;
    if (*(int*)(_this + 0x24) != 0) return;
    char* status = _this + 0x3C;
    *(float*)(_this + 0x28) = dt;
    float* secInState = (float*)(status + 0x14);
    *secInState = *secInState + dt;
    int didTransition = 0;
    void* callState = *(void**)(_this + 0x84);
    if (callState != 0) {
        while (*(void**)(_this + 0x84) != 0) {
            didTransition = 1;
            void* nextCall = *(void**)(_this + 0x84);
            *(void**)(_this + 0x84) = 0;
            void* prevState = *(void**)(status);
            // Push status, reset, set calling state, set new state
            *(int*)(_this + 0x90) = 0;
            (void)nextCall; (void)prevState;
        }
    }
    int retFlag = *(int*)(_this + 0x88);
    if (retFlag != 0) {
        void* prevState = *(void**)(status);
        // ShutdownCurState, PopStatus
        int retStateId = *(int*)(_this + 0x8C);
        *(int*)(_this + 0x88) = 0;
        *(void**)(_this + 0x44) = prevState;
        *(int*)(_this + 0x90) = retStateId;
    }
    // Process timer and next state transitions
    void* nextState = *(void**)(_this + 0x40);
    if (nextState != 0) {
        float timer = *(float*)(_this + 0x4C);
        if (timer == 0.0f) {
            didTransition = 1;
            while (nextState != 0) {
                *(void**)(_this + 0x40) = 0;
                // SetState(nextState)
                nextState = *(void**)(_this + 0x40);
                if (nextState == 0) break;
                timer = *(float*)(_this + 0x4C);
                if (timer != 0.0f) break;
            }
        }
    }
    if (didTransition != 0) {
        // Call Startup on current state via vtable
        void* curState = *(void**)(status);
        if (curState != 0) {
            void** vtbl = *(void***)((char*)curState + 0x18);
            short adj = *(short*)((char*)vtbl + 0x20);
            void (*fn)(void*) = (void(*)(void*))*(void**)((char*)vtbl + 0x24);
            fn((char*)curState + adj);
        }
        int pending = *(int*)(*(char**)(status) + 0x14);
        if (pending == 0) return;
    }
    // UpdateCurState(dt)
    void* cs = *(void**)(status);
    if (cs != 0) {
        void** vtbl = *(void***)((char*)cs + 0x18);
        short adj = *(short*)((char*)vtbl + 0x28);
        void (*fn)(void*, float) = (void(*)(void*, float))*(void**)((char*)vtbl + 0x2C);
        fn((char*)cs + adj, dt);
    }
}

// 0x80095f10 - 368 bytes - StateMachine::AddState(StateMachineState*)
// NON_MATCHING - vector push_back with small/large alloc
void StateMachine_AddState(void* self, void* pState) {
    char* _this = (char*)self;
    // Check if state already in vector (FindState)
    void** begin = *(void***)(_this + 0x2C);
    void** end = *(void***)(_this + 0x30);
    void** iter = begin;
    while (iter != end) {
        if (*iter == pState) {
            *(void**)((char*)pState + 0x08) = self;
            return;
        }
        iter++;
    }
    void** capEnd = *(void***)(_this + 0x38);
    if (end != capEnd) {
        *end = pState;
        *(void***)(_this + 0x30) = end + 1;
    } else {
        int count = (int)((char*)end - (char*)begin) >> 2;
        int newCount = count + 1;
        int newBytes = newCount * 4;
        void** newBuf;
        if (newBytes == 0) { newBuf = 0; newBytes = 0; }
        else if ((unsigned int)newBytes > 128) newBuf = (void**)operator_new_wrapper(newBytes);
        else newBuf = (void**)small_alloc(newBytes);
        void** newEnd;
        if (end != begin) {
            int copySize = (int)((char*)end - (char*)begin);
            memcpy(newBuf, begin, copySize);
            newEnd = (void**)((char*)newBuf + copySize);
        } else { newEnd = newBuf; }
        *newEnd = pState;
        newEnd++;
        if (begin != 0) {
            int oldSize = (int)((char*)capEnd - (char*)begin);
            if ((unsigned int)oldSize > 128) operator_delete_wrapper(begin);
            else small_free(begin);
        }
        *(void***)(_this + 0x2C) = newBuf;
        *(void***)(_this + 0x38) = (void**)((char*)newBuf + newBytes);
        *(void***)(_this + 0x30) = newEnd;
    }
    *(void**)((char*)pState + 0x08) = self;
}

// 0x80096080 - 308 bytes - StateMachine::DeleteAllStates(void)
// NON_MATCHING - vtable dtor dispatch, vector swap
void StateMachine_DeleteAllStates(void* self) {
    char* _this = (char*)self;
    char* status = _this + 0x3C;
    // ShutdownCurState
    *(void**)(status) = 0;
    *(float*)(status + 0x10) = -1.0f;
    void** begin = *(void***)(_this + 0x2C);
    void** end = *(void***)(_this + 0x30);
    while (begin != end) {
        void* state = *begin;
        if (state != 0) {
            void** vtbl = *(void***)((char*)state + 0x18);
            short adj = *(short*)((char*)vtbl + 0x08);
            void (*fn)(void*, int) = (void(*)(void*, int))*(void**)((char*)vtbl + 0x0c);
            fn((char*)state + adj, 3);
        }
        *begin = 0;
        begin++;
    }
    void** oldBegin = *(void***)(_this + 0x2C);
    *(void***)(_this + 0x2C) = 0;
    *(void***)(_this + 0x30) = 0;
    if (oldBegin != 0) {
        int size = (int)((char*)*(void***)(_this + 0x38) - (char*)oldBegin);
        size &= ~3;
        if ((unsigned int)size > 128) operator_delete_wrapper(oldBegin);
        else small_free(oldBegin);
    }
}

// 0x803a159c - 456 bytes - deque<StateMachineStatus*>::_M_reallocate_map
// NON_MATCHING - STL deque internal
void deque_reallocate_map(void* deq, unsigned int nodes_to_add, int add_at_front) {
    (void)deq; (void)nodes_to_add; (void)add_at_front;
}
