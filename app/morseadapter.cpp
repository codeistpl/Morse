#include "morseadapter.h"
#include "../morse/morse.h"

QString morse_adapter::encode(const QString &literal) {
  auto str = morse::encode(literal.toStdString());
  return QString::fromStdString(str);
}

QString morse_adapter::decode(const QString &code) {
  auto str = morse::decode(code.toStdString());
  return QString::fromStdString(str);
}
