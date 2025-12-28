#include "about_dialog.h"
#include "ui_about_dialog.h"

#include "rpcs3_version.h"
#include "qt_utils.h"

#include <QDesktopServices>
#include <QUrl>
#include <QSvgWidget>

about_dialog::about_dialog(QWidget* parent) : QDialog(parent), ui(new Ui::about_dialog)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);

	ui->close->setDefault(true);
	ui->icon->load(QStringLiteral(":/rpcs3.svg"));
	ui->version->setText(tr("R3 Version: %1").arg(QString::fromStdString(rpcs3::get_verbose_version())));
	ui->description->setText(gui::utils::make_paragraph(tr(
		"R3 is a network-enhanced fork of RPCS3 designed for reverse engineering and custom server development.\n"
		"Based on the excellent RPCS3 emulator, R3 adds powerful network interception capabilities.\n"
		"This fork is for game preservation and research purposes only.\n"
		"For regular PS3 emulation, please use mainline RPCS3."));

	// Events
	connect(ui->gitHub, &QPushButton::clicked, [] { QDesktopServices::openUrl(QUrl("https://github.com/MORKI211/R3")); });
	connect(ui->website, &QPushButton::clicked, [] { QDesktopServices::openUrl(QUrl("https://github.com/MORKI211/R3")); });
	connect(ui->forum, &QPushButton::clicked, [] { QDesktopServices::openUrl(QUrl("https://github.com/MORKI211/R3/discussions")); });
	connect(ui->patreon, &QPushButton::clicked, [] { QDesktopServices::openUrl(QUrl("https://rpcs3.net")); });  // Original RPCS3
	connect(ui->discord, &QPushButton::clicked, [] { QDesktopServices::openUrl(QUrl("https://discord.gg/rpcs3")); });  // Original RPCS3
	connect(ui->wiki, &QPushButton::clicked, [] { QDesktopServices::openUrl(QUrl("https://wiki.rpcs3.net/index.php?title=Main_Page")); });  // Original RPCS3
	connect(ui->close, &QPushButton::clicked, this, &QWidget::close);
}

about_dialog::~about_dialog()
{
}
