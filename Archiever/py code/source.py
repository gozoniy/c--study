import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QTreeView, QFileSystemModel, QPushButton, QFileDialog, QLineEdit, QLabel, QProgressDialog
from PyQt5.QtCore import Qt, QThread, pyqtSignal
from PyQt5.QtGui import QIcon
import zipfile
import os
from ArchiveTreads import *
from FileExplorer import *

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = FileExplorer()
    window.show()
    sys.exit(app.exec_())