/****************************************************************************
** Meta object code from reading C++ file 'convertwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../convertwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'convertwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSConvertWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSConvertWidgetENDCLASS = QtMocHelpers::stringData(
    "ConvertWidget",
    "exit",
    "",
    "on_btnClicked",
    "on_OpenPath",
    "on_SavePath",
    "on_Start",
    "on_threadfinish",
    "addLogText",
    "text",
    "addtime",
    "on_exit",
    "on_clear",
    "on_deleteUser",
    "on_changpassword"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSConvertWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   87,    2, 0x0a,    2 /* Public */,
       4,    0,   88,    2, 0x0a,    3 /* Public */,
       5,    0,   89,    2, 0x0a,    4 /* Public */,
       6,    0,   90,    2, 0x0a,    5 /* Public */,
       7,    0,   91,    2, 0x0a,    6 /* Public */,
       8,    2,   92,    2, 0x0a,    7 /* Public */,
       8,    1,   97,    2, 0x2a,   10 /* Public | MethodCloned */,
      11,    0,  100,    2, 0x0a,   12 /* Public */,
      12,    0,  101,    2, 0x0a,   13 /* Public */,
      13,    0,  102,    2, 0x0a,   14 /* Public */,
      14,    0,  103,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    9,   10,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ConvertWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSConvertWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSConvertWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSConvertWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ConvertWidget, std::true_type>,
        // method 'exit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_OpenPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SavePath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_threadfinish'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addLogText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'addLogText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_exit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_changpassword'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ConvertWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConvertWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->exit(); break;
        case 1: _t->on_btnClicked(); break;
        case 2: _t->on_OpenPath(); break;
        case 3: _t->on_SavePath(); break;
        case 4: _t->on_Start(); break;
        case 5: _t->on_threadfinish(); break;
        case 6: _t->addLogText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 7: _t->addLogText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->on_exit(); break;
        case 9: _t->on_clear(); break;
        case 10: _t->on_deleteUser(); break;
        case 11: _t->on_changpassword(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConvertWidget::*)();
            if (_t _q_method = &ConvertWidget::exit; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ConvertWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConvertWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSConvertWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ConvertWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ConvertWidget::exit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
