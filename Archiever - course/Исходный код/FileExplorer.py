import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QTreeView, QFileSystemModel, QPushButton, QFileDialog, QLineEdit, QLabel, QProgressDialog, QInputDialog
from PyQt5.QtCore import Qt, QThread, pyqtSignal
from PyQt5.QtGui import QIcon
import zipfile
import os
from ArchiveTreads import *

class FileExplorer(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Архиватор')
        self.setWindowIcon(QIcon('icons/icon.png'))
        self.setGeometry(100, 100, 800, 600)

        # Создаем модель файловой системы
        self.model = QFileSystemModel()
        self.model.setRootPath('')

        # Создаем виджеты представления файловой системы и устанавливаем модель
        self.tree = QTreeView()
        self.tree.setModel(self.model)
        self.tree.setRootIndex(self.model.index(''))  # Устанавливаем корневой индекс
        self.tree.doubleClicked.connect(self.open_file)
        self.tree.setSelectionMode(QTreeView.ExtendedSelection)  # Разрешаем множественный выбор
        self.tree.setColumnWidth(0, 200)
        self.tree.setSortingEnabled(True)
        
            
        # Создаем окно пути
        self.path_line_edit = QLineEdit()
        self.path_line_edit.setPlaceholderText('Путь к файлам...')
        self.go_button = QPushButton()
        self.go_button.setIcon(QIcon("icons/go_icon.png"))
        self.go_button.clicked.connect(self.change_directory)

        self.up_button = QPushButton()
        self.up_button.setIcon(QIcon("icons/up_icon.png"))
        self.up_button.clicked.connect(self.go_up)
        
        #архивацией и поиском
        self.add_button = QPushButton('Добавить')
        self.extract_button = QPushButton('Извлечь')

        self.home_button = QPushButton()
        self.home_button.setIcon(QIcon("icons/home_icon.png"))
        # Соединяем сигнал кнопки с методом
        self.home_button.clicked.connect(self.go_home)
        
        self.pc_button = QPushButton()
        self.pc_button.setIcon(QIcon("icons/pc_icon.png"))
        # Соединяем сигнал кнопки с методом
        self.pc_button.clicked.connect(self.pc)

        

        # Соединяем сигналы кнопок с методами
        self.add_button.clicked.connect(self.create_zip)
        self.extract_button.clicked.connect(self.extract_zip)


        # Создаем горизонтальный макет для кнопок управления
        button_layout = QHBoxLayout()
        button_layout.addWidget(self.home_button)
        button_layout.addWidget(self.pc_button)
        button_layout.addWidget(self.up_button)
        button_layout.addWidget(self.path_line_edit)
        button_layout.addWidget(self.go_button)
        button_layout.addWidget(self.add_button)
        button_layout.addWidget(self.extract_button)
        button_layout.addWidget(self.path_line_edit)
        

        

        # Создаем вертикальный макет и добавляем виджет представления файловой системы и кнопки управления
        layout = QVBoxLayout()
        layout.addLayout(button_layout)
        layout.addWidget(self.tree)

        # Устанавливаем макет для главного окна
        self.setLayout(layout)

        # Подключаем обработчик события выбора элемента в дереве
        self.tree.selectionModel().selectionChanged.connect(self.update_path_label)

    def go_home(self):
        home_path = os.path.expanduser("~")  # Получаем путь к домашней директории пользователя
        self.model.setRootPath(home_path)  # Устанавливаем новый корневой путь для модели
        self.tree.setRootIndex(self.model.index(home_path))  # Обновляем представление
        self.path_line_edit.setText(home_path)  # Обновляем поле ввода пути
        
    def pc(self):
        self.model.setRootPath('')  # Устанавливаем новый корневой путь для модели
        self.tree.setRootIndex(self.model.index(''))  # Обновляем представление
        self.path_line_edit.setText('')  # Обновляем поле ввода пути
        
    def go_up(self):
        current_path = self.path_line_edit.placeholderText().strip()  # Получаем текущий путь из плейсхолдера поля ввода        

        parent_path = os.path.dirname(current_path)  # Получаем родительскую директорию текущего пути
        if os.path.isdir(parent_path):  # Проверяем, существует ли родительская директория

            self.model.setRootPath(parent_path)  # Устанавливаем родительскую директорию как новый корневой путь для модели
            self.tree.setRootIndex(self.model.index(parent_path))  # Обновляем представление
            self.path_line_edit.setPlaceholderText(parent_path)  # Обновляем поле ввода пути
        else:
            self.go_home()
               
    def open_file(self, index):
        # Получаем путь к файлу или директории по индексу
        path = self.model.filePath(index)

        
        if os.path.isfile(path):
            os.startfile(path)  # Запускаем файл
        elif os.path.isdir(path):
            self.model.setRootPath(path)
            self.tree.setRootIndex(index)
            self.path_line_edit.setPlaceholderText(path)
            self.path_line_edit.clear()
            
    def update_path_label(self):
        # Получаем путь выбранного элемента и обновляем текст окна пути
        selected_index = self.tree.currentIndex()
        path = self.model.filePath(selected_index)
        self.path_line_edit.setPlaceholderText(f'{path}')

    def change_directory(self):
        # Получаем путь из поля ввода
        path = self.path_line_edit.text().strip()
        if not path:
            return
        # Устанавливаем новый корневой путь для модели
        self.model.setRootPath(path)
        self.tree.setRootIndex(self.model.index(path))
 

    def create_zip(self):
        # Получаем список выбранных файлов и директорий
        selected_indexes = list(set(self.tree.selectionModel().selectedIndexes()))
        paths = list(set([self.model.filePath(index) for index in selected_indexes]))
        # Открываем встроенное диалоговое окно для выбора места сохранения архива
        save_path, _ = QFileDialog.getSaveFileName(self, 'Сохранить как', '', 'ZIP Archive (*.zip)')
        if not save_path:
            return  # Отменено пользователем или не выбран путь сохранения

        # Создаем диалоговое окно процесса сжатия
        progress_dialog = QProgressDialog(self)
        progress_dialog.setWindowTitle('Создание архива')
        progress_dialog.setLabelText('Идет процесс создания архива...')
        progress_dialog.setCancelButton(None)
        progress_dialog.setRange(0, 0)  # Бесконечный режим прогресса

        # Запускаем поток сжатия
        compression_thread = CompressionThread(paths, save_path)
        compression_thread.updateProgress.connect(progress_dialog.setValue)
        compression_thread.compressionFinished.connect(progress_dialog.cancel)
        compression_thread.start()

        # Отображаем диалоговое окно процесса сжатия
        progress_dialog.exec_()


    def extract_zip(self):
        selected_indexes = list(set(self.tree.selectionModel().selectedIndexes()))
        zips_path = list(set([self.model.filePath(index) for index in selected_indexes]))
        # Открываем диалоговое окно для выбора архива для извлечения
        extract_path = QFileDialog.getExistingDirectory(self, 'Выбрать место извлечения')
        if not extract_path:
            return  # Отменено пользователем или не выбрано место извлечения
        for zips in zips_path:
            if not zips:
                return  # Отменено пользователем или не выбран архив
            if zips[:-3]=='zip':
                # Извлекаем архив
                with zipfile.ZipFile(zips, 'r') as zipf:
                    zipf.extractall(extract_path)
