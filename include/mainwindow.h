#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    void createWindow();
public:
    explicit MainWindow(QWidget *parent = nullptr);
};