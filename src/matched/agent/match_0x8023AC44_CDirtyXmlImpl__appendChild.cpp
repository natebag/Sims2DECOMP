extern int CDirtyXmlNode_appendChild(void *self);

struct CDirtyXmlImpl {
    int appendChild();
};

int CDirtyXmlImpl::appendChild() {
    return CDirtyXmlNode_appendChild(this);
}
