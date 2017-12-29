/****************************************************************************
** Meta object code from reading C++ file 'grabscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../grabscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grabscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_grabScreen_t {
    QByteArrayData data[12];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_grabScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_grabScreen_t qt_meta_stringdata_grabScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "grabScreen"
QT_MOC_LITERAL(1, 11, 17), // "onTrayIconClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(4, 64, 6), // "reason"
QT_MOC_LITERAL(5, 71, 14), // "grabFullScreen"
QT_MOC_LITERAL(6, 86, 9), // "onCapture"
QT_MOC_LITERAL(7, 96, 10), // "showWidget"
QT_MOC_LITERAL(8, 107, 1), // "t"
QT_MOC_LITERAL(9, 109, 10), // "quitWidget"
QT_MOC_LITERAL(10, 120, 5), // "onMin"
QT_MOC_LITERAL(11, 126, 7) // "onClose"

    },
    "grabScreen\0onTrayIconClicked\0\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0grabFullScreen\0onCapture\0"
    "showWidget\0t\0quitWidget\0onMin\0onClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_grabScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    1,   54,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,
      10,    0,   60,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void grabScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        grabScreen *_t = static_cast<grabScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTrayIconClicked((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 1: _t->grabFullScreen(); break;
        case 2: _t->onCapture(); break;
        case 3: _t->showWidget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->quitWidget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onMin(); break;
        case 6: _t->onClose(); break;
        default: ;
        }
    }
}

const QMetaObject grabScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_grabScreen.data,
      qt_meta_data_grabScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *grabScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *grabScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_grabScreen.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int grabScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
