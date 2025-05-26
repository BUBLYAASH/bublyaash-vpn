#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT
private:
    void createWindow();
public:
    explicit MainWindow(QWidget *parent = nullptr);
};