#include <QApplication>
#include "window.h"
#include "SocketClient.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MainWindow window;

    window.resize(300, 190);
    window.setWindowTitle("Button");
    window.show();

    return app.exec();
}
