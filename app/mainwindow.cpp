#include "mainwindow.h"
#include "../morse/morse.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()),
          Qt::DirectConnection);
  connect(ui->morseEdit, SIGNAL(textChanged()), this, SLOT(onMorseChanged()),
          Qt::DirectConnection);
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::onTextChanged() {
  auto oldState = ui->morseEdit->blockSignals(true);
  ui->morseEdit->setPlainText(QString::fromStdString(
      morse::encode(ui->textEdit->toPlainText().toStdString())));
  ui->morseEdit->blockSignals(oldState);
}

void MainWindow::onMorseChanged() {
  auto oldState = ui->textEdit->blockSignals(true);
  ui->textEdit->setPlainText(QString::fromStdString(
      morse::decode(ui->morseEdit->toPlainText().toStdString())));
  ui->textEdit->blockSignals(oldState);
}
