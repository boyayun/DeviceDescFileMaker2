#ifndef CONFIG
#define CONFIG

#include <QDebug>

//#define VERSION_APP "1.0"
//#define VERSION_FILE "01"

//#define TABLE_USERINFO QString("user_info") // table of user information
//#define TABLE_USER       QString("user")      // table of user
//#define TALBE_CMDTYPE   QString("command_type")// table of command type
//#define TABLE_DEVCLASS1  QString("device_class1") // table of device class 1
//#define TABLE_DEVCLASS2   QString("device_class2") // table of device calss 2
//#define TABLE_PARADAUFT  QString ("parameter_defalut") //
//#define TABLE_GCMD       QString ("general_command")
//#define TABLE_FUNCTION   QString ("function")
//#define TABLE_DEVICE     QString("device")

#ifndef USE_DEBUG_MODE
#define PRINTLOG(x) qDebug()<<__FILE__<<__LINE__<<(x);
#else
#define PRINTLOG(x);
#endif

#endif // CONFIG

