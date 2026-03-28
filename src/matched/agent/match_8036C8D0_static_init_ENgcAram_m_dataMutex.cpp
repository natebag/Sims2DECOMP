/* 0x8036C8D0 (84 bytes) - __static_initialization_and_destruction_0 */

extern char ENgcAram__m_dataMutex[];

void EMutex_ctor(void*);
void EMutex_dtor(void*, int);

void __static_initialization_and_destruction_0_157(int initialize, int priority) {
    if (priority != 0xFFFF) {
        return;
    }

    if (initialize != 0) {
        EMutex_ctor(ENgcAram__m_dataMutex);
    } else {
        EMutex_dtor(ENgcAram__m_dataMutex, 2);
    }
}
