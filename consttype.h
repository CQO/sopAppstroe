#ifndef CONSTTYPE_H
#define CONSTTYPE_H

#define LINKDOOD_SOPID "com.vrv.sopstore"

#define DBUS_DOOD_SERVICE "com.vrv.sopstore"
#define DBUS_DOOD_PATH "/sopstoreservice"
#define DBUS_DOOD_INTERFACE "com.vrv.sopstore"
//"baqi.linkdood.cn"
#define SERVICE_IP "10.152.142.20"
#define  APP_DATA_CACHE    "/data/data/com.vrv.sopstore/.data"
#define  APP_DIR    "/data/data/com.vrv.sopstore/apps/"
//10.152.142.20
#define GET_DATA(FUNC) QDBusInterface manager(DBUS_DOOD_SERVICE,DBUS_DOOD_PATH,DBUS_DOOD_INTERFACE,QDBusConnection::sessionBus());manager.call(""#FUNC)
#define GET_DATA_PARAMS(FUNC,ARGS) QDBusInterface manager(DBUS_DOOD_SERVICE,DBUS_DOOD_PATH,DBUS_DOOD_INTERFACE,QDBusConnection::sessionBus());manager.call(""#FUNC,ARGS)
#define CONNECT_DEBUS(_SIGNAL,_SLOT) QDBusConnection::sessionBus().connect(DBUS_DOOD_SERVICE, DBUS_DOOD_PATH,DBUS_DOOD_INTERFACE,""#_SIGNAL, this, SLOT(on##_SLOT))
#endif // CONSTTYPE_H
