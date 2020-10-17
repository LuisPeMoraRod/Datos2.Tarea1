#include <QApplication>
#include "window.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MainWindow window;

    window.resize(950, 400);
    window.setWindowTitle("Floyd-Warshall Algorithm Test");
    window.show();

    return app.exec();
}
