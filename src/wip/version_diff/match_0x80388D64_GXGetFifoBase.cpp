struct GXFifoObj {
    void *m_base;
};
void *GXGetFifoBase(GXFifoObj *fifo);
void *GXGetFifoBase(GXFifoObj *fifo) { return fifo->m_base; }
