# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'Drag-Drop.ui'
##
## Created by: Qt User Interface Compiler version 5.14.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import (QCoreApplication, QMetaObject, Qt)
from PySide2.QtWidgets import *
import PySide2

file_path = ""
file_path_temp = ""
class tableWidgetMain(QTableWidget):
    def __init__(self, parent):
        super(tableWidgetMain, self).__init__(parent)
        self.setAcceptDrops(True)
        self.setDragEnabled(True)

    def dragEnterEvent(self, event:PySide2.QtGui.QDragEnterEvent):
        if event.mimeData().hasUrls():
            event.accept()
        else:
            event.ignore()

    def dragMoveEvent(self, event:PySide2.QtGui.QDragMoveEvent):
        if event.mimeData().hasUrls():
            event.setDropAction(Qt.CopyAction)
            event.accept()
        else:
            event.ignore()

    def dropEvent(self, event:PySide2.QtGui.QDropEvent):
        global file_path
        global file_path_temp

        if event.mimeData().hasUrls():
            event.setDropAction(Qt.CopyAction)
            event.accept()

            for url in event.mimeData().urls():
                file_path_temp = url.toLocalFile()
            print(file_path_temp)
            # Show file path in console and messagebox
            self.infoBox = QMessageBox()
            self.infoBox.setWindowTitle("File Path")
            self.infoBox.setText(file_path_temp)
            self.infoBox.show()

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(700, 500)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        
        self.horizontalLayout = QHBoxLayout(self.centralwidget)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        

        self.splitter = QSplitter(self.centralwidget)
        self.splitter.setObjectName(u"splitter")
        self.splitter.setOrientation(Qt.Horizontal)

        self.tableWidget = tableWidgetMain(self.splitter)
        self.horizontalLayout.addWidget(self.splitter)
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
    # retranslateUi


import sys
from PySide2.QtWidgets import *
from PySide2 import QtCore, QtWidgets, QtGui
from PySide2.QtCore import Qt

if __name__ == '__main__':
     app = QtWidgets.QApplication(sys.argv)
     ex = Ui_MainWindow()
     w = QtWidgets.QMainWindow()
     ex.setupUi(w)
     w.show()
     sys.exit(app.exec_())
