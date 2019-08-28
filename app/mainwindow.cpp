#include "mainwindow.h"
#include "../morse/morse.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QPlainTextEdit>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(onTextChanged()),
          Qt::DirectConnection);
  connect(ui->morseEdit, SIGNAL(textChanged()), this, SLOT(onMorseChanged()),
          Qt::DirectConnection);
  connect(ui->actionLoad_Text, SIGNAL(triggered()), this,
          SLOT(onLoadTextFile()));
  connect(ui->actionLoad_Morse, SIGNAL(triggered()), this,
          SLOT(onLoadMorseFile()));
  connect(ui->actionSave_Text, SIGNAL(triggered()), this, SLOT(onSaveText()));
  connect(ui->actionSave_Morse, SIGNAL(triggered()), this, SLOT(onSaveMorse()));
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

void MainWindow::onLoadTextFile() {
  auto path = QFileDialog::getOpenFileName(this, "Load Text File", "", "*.txt");
  if (path.isEmpty())
    return;

  QFile f(path);
  if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    return;

  QString text;
  QTextStream in(&f);
  while (!in.atEnd()) {
    text.append(in.readLine());
  }
  ui->textEdit->setPlainText(text);
  f.close();
}

void MainWindow::onLoadMorseFile() {
  auto path =
      QFileDialog::getOpenFileName(this, "Load Morse File", "", "*.txt");
  if (path.isEmpty())
    return;

  QFile f(path);
  if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    return;

  QString text;
  QTextStream in(&f);
  while (!in.atEnd()) {
    text.append(in.readLine());
  }
  ui->morseEdit->setPlainText(text);
  f.close();
}

void MainWindow::onSaveText() {
  auto path = QFileDialog::getSaveFileName(this, "Save Text As", "", "*.txt");
  if (path.isEmpty())
    return;

  QFile f(path);
  if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

  QTextStream out(&f);
  out << ui->textEdit->toPlainText();
  f.close();
}

void MainWindow::onSaveMorse() {
  auto path = QFileDialog::getSaveFileName(this, "Save Morse As", "", "*.txt");
  if (path.isEmpty())
    return;

  QFile f(path);
  if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

  QTextStream out(&f);
  out << ui->morseEdit->toPlainText();
  f.close();
}
