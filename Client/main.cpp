#include <QApplication>
#include "window.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Form window;

    window.resize(300, 190);
    window.setWindowTitle("Button");
    window.show();

    return app.exec();
}
