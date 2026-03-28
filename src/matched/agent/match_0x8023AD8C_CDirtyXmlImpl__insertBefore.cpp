extern int CDirtyXmlNode_insertBefore(void *self);

struct CDirtyXmlImpl {
    int insertBefore();
};

int CDirtyXmlImpl::insertBefore() {
    return CDirtyXmlNode_insertBefore(this);
}
