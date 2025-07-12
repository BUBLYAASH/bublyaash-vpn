#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QNetworkReply>

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    void createWindow();
    void onServersDownloaded(QNetworkReply *reply);
    QComboBox *serversList;
public:
    explicit MainWindow(QWidget *parent = nullptr);
};