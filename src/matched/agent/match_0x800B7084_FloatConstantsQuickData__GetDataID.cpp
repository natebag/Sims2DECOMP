void QD_GetDataID_impl(void *, void *);

struct QD_GDI {
    QD_GDI *GetDataID(void *param);
};

QD_GDI *QD_GDI::GetDataID(void *param) {
    QD_GetDataID_impl(this, (char *)param + 4);
    return this;
}
