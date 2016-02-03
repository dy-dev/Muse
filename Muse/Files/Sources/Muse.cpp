#include <QListWidget>
#include <QCompleter>
#include "Muse.h"

Muse::Muse(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QStringList wordList;
	wordList << "alpha" << "omega" << "omicron" << "zeta";

	//QLineEdit *lineEdit = new QLineEdit(this);

	QCompleter *completer = new QCompleter(wordList, this);
	completer->setCaseSensitivity(Qt::CaseInsensitive);
	//ui.textEdit->setcompl(completer);

	ui.Subject_listWidget->addItem("Voleur");
	ui.Subject_listWidget->addItem("Gendarme");
	ui.Subject_listWidget->addItem("Extraterrestre");
	ui.Subject_listWidget->addItem("Nounou");
	ui.Subject_listWidget->addItem("Cowboy");

	ui.Verb_listWidget->addItem("cours");
	ui.Verb_listWidget->addItem("mange");
	ui.Verb_listWidget->addItem("fuit");
	ui.Verb_listWidget->addItem("range");
	ui.Verb_listWidget->addItem("galope");


	ui.Complement_listWidget->addItem("dans la ville");
	ui.Complement_listWidget->addItem(QString::fromStdWString(L"des fruits et légume"));
	ui.Complement_listWidget->addItem(QString::fromStdWString(L"sa planète"));
	ui.Complement_listWidget->addItem("les affaires des enfants");
	ui.Complement_listWidget->addItem("dans les plaines");
}

Muse::~Muse()
{

}
