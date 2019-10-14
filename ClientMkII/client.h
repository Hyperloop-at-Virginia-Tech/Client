#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QNetworkSession>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QHostInfo>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QGuiApplication>
#include <QStyleHints>
#include <QRandomGenerator>
#include <QDebug>

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void requestNewData();
    void readData();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetDataButton();
    void sessionOpened();

private:
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QPushButton *getDataButton;

    QTcpSocket *clientSocket;
    QDataStream in;
    QString currentData;

    QNetworkSession *networkSession = nullptr;

    Ui::Client *ui;

};
#endif // CLIENT_H
