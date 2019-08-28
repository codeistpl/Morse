#pragma once
#include <QString>

namespace morse_adapter {
QString encode(const QString &literal);
QString decode(const QString &code);
}; // namespace morse_adapter
