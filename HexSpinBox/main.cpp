#include "hexspinbox.h"
#include "iconeditor.h"
#include <QApplication>


int main( int argc, char* argv[])
{
    QApplication a(argc, argv);
    //HexSpinBox  spinbox;
    IconEditor editor;
    //spinbox.setWindowTitle("hex spin box");

    //spinbox.show();
    editor.show();
    return a.exec();
}
