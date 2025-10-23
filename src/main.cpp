/*
 * SPDX-FileCopyrightText: 2011-2018 Project Lemon, Zhipeng Jia
 * SPDX-FileCopyrightText: 2018-2019 Project LemonPlus, Dust1404
 * SPDX-FileCopyrightText: 2019-2022 Project LemonLime
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include "lemon.h"
#include "spdlog/sinks/stdout_color_sinks.h"
//
#include "base/LemonBase.hpp"
#include "base/LemonBaseApplication.hpp"
#include "base/LemonLog.hpp"
#include "spdlog/sinks/daily_file_sink.h"
//
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <chrono>
#include <QPalette>
#include <QStyleFactory>

#define LEMON_MODULE_NAME "Main"

void initLogger() {
	auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	console_sink->set_level(spdlog::level::warn);
	QDir logDir(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + QDir::separator() +
	            "logs");
	logDir.mkpath(".");
	// retain last 30 days logs
	auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(
	    (logDir.path() + QDir::separator() + "lemonlime-log.txt").toStdString(), 0, 0, false, 30);
	file_sink->set_level(spdlog::level::trace);
	Lemon::base::logger =
	    std::make_shared<spdlog::logger>(spdlog::logger("lemonlime", {console_sink, file_sink}));
	spdlog::flush_every(std::chrono::seconds(5));
}

void ApplyDarkTheme(QApplication& app) {
  app.setStyle(QStyleFactory::create("Fusion"));
  
  QPalette dark_palette;
  dark_palette.setColor(QPalette::Window, QColor(53, 53, 53));
  dark_palette.setColor(QPalette::WindowText, Qt::white);
  dark_palette.setColor(QPalette::Base, QColor(35, 35, 35));
  dark_palette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
  dark_palette.setColor(QPalette::ToolTipBase, QColor(25, 25, 25));
  dark_palette.setColor(QPalette::ToolTipText, Qt::white);
  dark_palette.setColor(QPalette::Text, Qt::white);
  dark_palette.setColor(QPalette::Button, QColor(53, 53, 53));
  dark_palette.setColor(QPalette::ButtonText, Qt::white);
  dark_palette.setColor(QPalette::BrightText, Qt::red);
  dark_palette.setColor(QPalette::Link, QColor(42, 130, 218));
  dark_palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
  dark_palette.setColor(QPalette::HighlightedText, Qt::black);
  dark_palette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(120, 120, 120));
  dark_palette.setColor(QPalette::Disabled, QPalette::Text, QColor(120, 120, 120));
  dark_palette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(120, 120, 120));
  dark_palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
  dark_palette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(120, 120, 120));
  dark_palette.setColor(QPalette::Disabled, QPalette::Button, QColor(45, 45, 45));
  
  app.setPalette(dark_palette);
  
  app.setStyleSheet(R"(
    QWidget {
      background-color: #353535;
      color: #ffffff;
    }
    QToolTip {
      color: #ffffff;
      background-color: #2a82da;
      border: 1px solid #555555;
      padding: 2px;
    }
    QPushButton {
      background-color: #404040;
      color: #ffffff;
      border: 1px solid #555555;
      padding: 6px 12px;
      border-radius: 3px;
      min-width: 60px;
      min-height: 24px;
      font: normal;
    }
    QPushButton:hover {
      background-color: #505050;
    }
    QPushButton:pressed {
      background-color: #303030;
    }
    QPushButton:disabled {
      color: #888888 !important;
      background-color: #2d2d2d !important;
      border: 1px solid #3d3d3d !important;
      padding: 6px 12px;
      min-width: 60px;
      min-height: 24px;
      font: normal;
    }
    QLineEdit, QTextEdit, QPlainTextEdit {
      background-color: #404040;
      color: #ffffff;
      border: 1px solid #555555;
      padding: 2px 5px;
      selection-background-color: #2a82da;
    }
    QLineEdit:disabled, QTextEdit:disabled, QPlainTextEdit:disabled {
      color: #888888 !important;
      background-color: #2d2d2d !important;
      border: 1px solid #3d3d3d !important;
    }
    QLabel {
      color: #ffffff;
      background-color: transparent;
    }
    QLabel:disabled {
      color: #888888 !important;
      background-color: transparent;
    }
    QCheckBox, QRadioButton {
      color: #ffffff;
      spacing: 5px;
    }
    QCheckBox:disabled, QRadioButton:disabled {
      color: #888888 !important;
    }
    QCheckBox::indicator {
      width: 13px;
      height: 13px;
    }
    QCheckBox::indicator:unchecked {
      border: 1px solid #555555;
      background-color: #404040;
    }
    QCheckBox::indicator:unchecked:disabled {
      border: 1px solid #3d3d3d;
      background-color: #2d2d2d;
    }
    QCheckBox::indicator:checked {
      border: 1px solid #555555;
      background-color: #2a82da;
    }
    QCheckBox::indicator:checked:disabled {
      border: 1px solid #3d3d3d;
      background-color: #1a5276;
    }
    QComboBox {
      background-color: #404040;
      color: #ffffff;
      border: 1px solid #555555;
      padding: 1px 5px;
      min-width: 75px;
    }
    QComboBox:disabled {
      color: #888888 !important;
      background-color: #2d2d2d !important;
      border: 1px solid #3d3d3d !important;
    }
    QComboBox::drop-down {
      border: none;
      width: 15px;
    }
    QComboBox::down-arrow {
      border: none;
      image: none;
      background-color: #555555;
      width: 10px;
      height: 10px;
    }
    QMenuBar {
      background-color: #353535;
      color: #ffffff;
    }
    QMenuBar::item:selected {
      background-color: #505050;
    }
    QMenu {
      background-color: #353535;
      color: #ffffff;
      border: 1px solid #555555;
    }
    QMenu::item:selected {
      background-color: #505050;
    }
    QMenu::item:disabled {
      color: #888888 !important;
      background-color: transparent;
    }
  )");
}

int main(int argc, char *argv[]) {

#ifndef LEMON_QT6
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // High DPI supported
	QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);
	QApplication::setHighDpiScaleFactorRoundingPolicy(
	    Qt::HighDpiScaleFactorRoundingPolicy::PassThrough); // Qt 6 compatibility
#endif

	QCoreApplication::setApplicationName("selfEval");

	initLogger();

	Lemon::LemonBaseApplication app(argc, argv);
  
  ApplyDarkTheme(app);

	app.Initialize();

	if (app.sendMessage("")) {
		app.activeWindow();
		return 0;
	}

#ifdef Q_OS_LINUX
	// fonts.setFamily("Noto Sans CJK SC");
#endif
#ifdef Q_OS_WIN32
	QFont fonts;
	fonts.setFamily("Microsoft YaHei");
	fonts.setHintingPreference(QFont::PreferNoHinting);
	SingleApplication::setFont(fonts);
#endif
#ifdef Q_OS_MAC
	// fonts.setFamily("PingFangSC-Regular");
#endif
	Q_INIT_RESOURCE(resource);
	QPixmap pixmap(":/logo/splash2.png");
	QSplashScreen screen(pixmap.scaled(450, 191, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	LemonLime w;
	qint64 startTime = QDateTime::currentMSecsSinceEpoch();
	int splashTime = w.getSplashTime();

	if (splashTime > 0) {
		screen.show();

		do {
			SingleApplication::processEvents();
		} while (QDateTime::currentMSecsSinceEpoch() - startTime <= splashTime);

		screen.finish(&w);
	}

	w.activateWindow();
	w.show();
	w.welcome();
	return app.exec();
}
