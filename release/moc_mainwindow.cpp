/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FrontWindow_t {
    QByteArrayData data[22];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrontWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrontWindow_t qt_meta_stringdata_FrontWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FrontWindow"
QT_MOC_LITERAL(1, 12, 4), // "open"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "build"
QT_MOC_LITERAL(4, 24, 6), // "upload"
QT_MOC_LITERAL(5, 31, 11), // "stopProgram"
QT_MOC_LITERAL(6, 43, 14), // "connectWithINI"
QT_MOC_LITERAL(7, 58, 11), // "updatePorts"
QT_MOC_LITERAL(8, 70, 9), // "reconnect"
QT_MOC_LITERAL(9, 80, 7), // "newFile"
QT_MOC_LITERAL(10, 88, 4), // "save"
QT_MOC_LITERAL(11, 93, 16), // "toggleBreakpoint"
QT_MOC_LITERAL(12, 110, 6), // "saveAs"
QT_MOC_LITERAL(13, 117, 8), // "watchLST"
QT_MOC_LITERAL(14, 126, 5), // "about"
QT_MOC_LITERAL(15, 132, 9), // "showExtPM"
QT_MOC_LITERAL(16, 142, 9), // "showExtDM"
QT_MOC_LITERAL(17, 152, 7), // "showRAM"
QT_MOC_LITERAL(18, 160, 13), // "showRegisters"
QT_MOC_LITERAL(19, 174, 12), // "showFirmware"
QT_MOC_LITERAL(20, 187, 10), // "eraseProgM"
QT_MOC_LITERAL(21, 198, 10) // "eraseDataM"

    },
    "FrontWindow\0open\0\0build\0upload\0"
    "stopProgram\0connectWithINI\0updatePorts\0"
    "reconnect\0newFile\0save\0toggleBreakpoint\0"
    "saveAs\0watchLST\0about\0showExtPM\0"
    "showExtDM\0showRAM\0showRegisters\0"
    "showFirmware\0eraseProgM\0eraseDataM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrontWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    1,  120,    2, 0x08 /* Private */,
       9,    0,  123,    2, 0x08 /* Private */,
      10,    0,  124,    2, 0x08 /* Private */,
      11,    0,  125,    2, 0x08 /* Private */,
      12,    0,  126,    2, 0x08 /* Private */,
      13,    0,  127,    2, 0x08 /* Private */,
      14,    0,  128,    2, 0x08 /* Private */,
      15,    0,  129,    2, 0x08 /* Private */,
      16,    0,  130,    2, 0x08 /* Private */,
      17,    0,  131,    2, 0x08 /* Private */,
      18,    0,  132,    2, 0x08 /* Private */,
      19,    0,  133,    2, 0x08 /* Private */,
      20,    0,  134,    2, 0x0a /* Public */,
      21,    0,  135,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FrontWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FrontWindow *_t = static_cast<FrontWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open(); break;
        case 1: { int _r = _t->build();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->upload(); break;
        case 3: _t->stopProgram(); break;
        case 4: _t->connectWithINI(); break;
        case 5: _t->updatePorts(); break;
        case 6: _t->reconnect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->newFile(); break;
        case 8: { int _r = _t->save();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->toggleBreakpoint(); break;
        case 10: { int _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->watchLST(); break;
        case 12: _t->about(); break;
        case 13: _t->showExtPM(); break;
        case 14: _t->showExtDM(); break;
        case 15: _t->showRAM(); break;
        case 16: _t->showRegisters(); break;
        case 17: _t->showFirmware(); break;
        case 18: _t->eraseProgM(); break;
        case 19: _t->eraseDataM(); break;
        default: ;
        }
    }
}

const QMetaObject FrontWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FrontWindow.data,
      qt_meta_data_FrontWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FrontWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrontWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FrontWindow.stringdata0))
        return static_cast<void*>(const_cast< FrontWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FrontWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
