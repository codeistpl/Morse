#ifndef MORSE_GLOBAL_H
#define MORSE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MORSE_LIBRARY)
#  define MORSESHARED_EXPORT Q_DECL_EXPORT
#else
#  define MORSESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MORSE_GLOBAL_H
