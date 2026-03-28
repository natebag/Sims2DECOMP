struct GXFifoObj {
    char _p[0x08];
    int m_size;
};
int GXGetFifoSize(GXFifoObj *fifo);
int GXGetFifoSize(GXFifoObj *fifo) { return fifo->m_size; }
