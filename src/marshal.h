#ifndef MARSHAL_H
#define MARSHAL_H

#include <qlist.h>
#include <qfile.h>
#include "sortdict.h"
#include "store.h"

class ArgumentList;
class BaseInfo;
class Grouping;
class SectionInfo;
class ListItemInfo;
class QCString;
class QGString;
class SectionDict;
class MemberSDict;
class GroupList;
class BodyInfo;
class DocInfo;
class MemberList;
class ExampleSDict;

#define NULL_LIST 0xffffffff

class FileStorage : public QFile, public StorageIntf
{
  public:
    FileStorage() : QFile() {}
    FileStorage( const QString &name) : QFile(name) {}
    int read(char *buf,uint size)        { return QFile::readBlock(buf,size); }
    int write(const char *buf,uint size) { return QFile::writeBlock(buf,size); }
};

//----- marshaling function: datatype -> byte stream --------------------

void marshalInt(StorageIntf *s,int v);
void marshalUInt(StorageIntf *s,uint v);
void marshalBool(StorageIntf *s,bool b);
void marshalQCString(StorageIntf *s,const QCString &str);
void marshalQGString(StorageIntf *s,const QGString &str);
void marshalArgumentList(StorageIntf *s,ArgumentList *argList);
void marshalArgumentLists(StorageIntf *s,QList<ArgumentList> *argLists);
void marshalBaseInfoList(StorageIntf *s, QList<BaseInfo> *baseList);
void marshalGroupingList(StorageIntf *s, QList<Grouping> *groups);
void marshalSectionInfoList(StorageIntf *s, QList<SectionInfo> *anchors);
void marshalItemInfoList(StorageIntf *s, QList<ListItemInfo> *sli);
void marshalObjPointer(StorageIntf *s,void *obj);
void marshalSectionDict(StorageIntf *s,SectionDict *sections);
void marshalMemberSDict(StorageIntf *s,MemberSDict *memberSDict);
void marshalDocInfo(StorageIntf *s,DocInfo *docInfo);
void marshalBodyInfo(StorageIntf *s,BodyInfo *bodyInfo);
void marshalGroupList(StorageIntf *s,GroupList *groupList);
void marshalMemberList(StorageIntf *s,MemberList *ml);
void marshalExampleSDict(StorageIntf *s,ExampleSDict *ed);
void marshalMemberLists(StorageIntf *s,SDict<MemberList> *mls);

//----- unmarshaling function: byte stream -> datatype ------------------

int                  unmarshalInt(StorageIntf *s);
uint                 unmarshalUInt(StorageIntf *s);
bool                 unmarshalBool(StorageIntf *s);
QCString             unmarshalQCString(StorageIntf *s);
QGString             unmarshalQGString(StorageIntf *s);
ArgumentList *       unmarshalArgumentList(StorageIntf *s);
QList<ArgumentList> *unmarshalArgumentLists(StorageIntf *s);
QList<BaseInfo> *    unmarshalBaseInfoList(StorageIntf *s);
QList<Grouping> *    unmarshalGroupingList(StorageIntf *s);
QList<SectionInfo> * unmarshalSectionInfoList(StorageIntf *s);
QList<ListItemInfo> *unmarshalItemInfoList(StorageIntf *s);
void *               unmarshalObjPointer(StorageIntf *s);
SectionDict *        unmarshalSectionDict(StorageIntf *s);
MemberSDict *        unmarshalMemberSDict(StorageIntf *s);
DocInfo *            unmarshalDocInfo(StorageIntf *s);
BodyInfo *           unmarshalBodyInfo(StorageIntf *s);
GroupList *          unmarshalGroupList(StorageIntf *s);
MemberList *         unmarshalMemberList(StorageIntf *s);
ExampleSDict *       unmarshalExampleSDict(StorageIntf *s);
SDict<MemberList> *  unmarshalMemberLists(StorageIntf *s);

#endif
