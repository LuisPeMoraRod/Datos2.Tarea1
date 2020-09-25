#include <QApplication>
#include "window.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MainWindow window;

    window.resize(1250, 200);
    window.setWindowTitle("Floyd-Warshall Algorithm Test");
    window.show();

    return app.exec();
}
