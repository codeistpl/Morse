#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

private slots:
  void onTextChanged();
  void onMorseChanged();
  void onLoadTextFile();
  void onLoadMorseFile();
  void onSaveText();
  void onSaveMorse();
};

#endif // MAINWINDOW_H
