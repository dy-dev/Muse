#ifndef MUSE_H
#define MUSE_H

#include <QtWidgets/QMainWindow>
#include "ui_Muse.h"

class Muse : public QMainWindow
{
	Q_OBJECT

public:
	Muse(QWidget *parent = 0);
	~Muse();

private:
	Ui::MuseClass ui;
};

#endif // MUSE_H
